//
// BinManager.cpp : Implements the BinManager class.
//

#include <iostream>
#include "BinManager.h"

using namespace std;

//
// Default constructor
//
BinManager::BinManager()
{
    // For now, the BinManager just holds 4 statically allocated bins. Later we'll
    // change this to dynamically create bin objects on demand and store the
    // pointers in a vector.

    // Valve bin
    bin1.setNumParts(10);
    bin1.setType("Knife Gate Valve");

    // TODO - instantiate the other three bin types after you've declared and
    // implemented the classes.

    // Gear bin
    bin2.setNumParts(5);
    bin2.setSize('S');

    // Cable bin
    bin3.setNumParts(35);
    bin3.setColor("Red");

    // Rod bin
    bin4.setNumParts(40);
    bin4.setLength(5);

    numBins = 4;
}

//
// Destructor
//
BinManager::~BinManager()
{

}

//
// This function is called to perform an update of a specific bin. It prompts
// the user to either add or remove parts from the bin.
// 
// Returns true if the bin was successfully updated, false if not.
//
bool BinManager::updateBin(int binNumber)
{
    bool success = false;

    // Get the user's desired action (A for add or R for remove)
    char choice;
    cout << "\nEnter A to add parts to the bin, or R to remove parts: ";
    cin >> choice;

    // Validate the input.
    while (toupper(choice) != 'A' && toupper(choice) != 'R')
    {
        cout << "Enter A or R: ";
        cin >> choice;
    }

    // Process the selection. 'A' means Add,
    // 'R' means Remove.
    int numParts = 0;
    if (toupper(choice) == 'A')
    {
        // Get the number of parts to add.
        cout << "How many parts to add? ";
        cin >> numParts;

        // Call the helper function to add the parts:
        success = addParts(binNumber, numParts);
    }
    else
    {
        // Get the number of parts to remove.
        cout << "How many parts to remove? ";
        cin >> numParts;

        // Call the helper function to remove the parts:
        success = removeParts(binNumber, numParts);
    }

    return success;
}

//
// This function is called to output information about each bin.
// 
// Later we'll learn to do this using polymorphism and a collection of bin
// object pointers, but for now, just print each of our four bins.
//
void BinManager::print()
{
    cout << "\nInventory Bin List:\n";
    cout << "Bin #1:\n";
    bin1.print();

    // TODO - print the other three bin types after you've declared and
    // implemented the classes.
    cout << "Bin #2:\n";
    bin2.print();
    cout << "Bin #3:\n";
    bin3.print();
    cout << "Bin #4:\n";
    bin4.print();
}

//
// These two private helper functions are called to add or remove parts for
// a specific bin. Validation is performed to ensure the amount of parts to
// add does not exceed the capacity of the bin, and that amount of parts to
// remove does not exceed what the bin currently holds.
// 
// Returns true if successful, false if not.
// 
bool BinManager::addParts(int binNumber, int numParts)
{
    bool success = false;

    // We'll use a switch statement for now to determine which of the derived
    // bin types to use. Later, when we implement polymorphism, we'll use
    // a much better method with a vector of pointers instead.
    InventoryBin* pBin = nullptr;
    switch (binNumber)
    {
    case 1:
    {
        pBin = static_cast<ValveBin*>(pBin);
        pBin = &bin1;
        break;
    }
    case 2:
    {
        // TODO - remove the comments after implementing the classes
        pBin = static_cast<GearBin*>(pBin);
        pBin = &bin2;
        break;
    }
    case 3:
    {
        // TODO - remove the comments after implementing the classes
        pBin = static_cast<CableBin*>(pBin);
        pBin = &bin3;
        break;
    }
    case 4:
    {
        // TODO - remove the comments after implementing the classes
        pBin = static_cast<RodBin*>(pBin);
        pBin = &bin4;
        break;
    }
    }

    if (numParts < 0)
    {
        cout << "\n** Error: number of parts cannot be negative.\n";
    }
    else if (pBin != nullptr)
    {
        if (numParts + pBin->getNumParts() > pBin->getMaxParts())
        {
            cout << "\n** Error: bin can only hold a maximum of " << pBin->getMaxParts() << " parts.\n";
        }
        else
        {
            pBin->setNumParts(numParts + pBin->getNumParts());
            success = true;
        }
    }

    return success;
}
bool BinManager::removeParts(int binNumber, int numParts)
{
    bool success = false;

    // We'll use a switch statement for now to determine which of the derived
    // bin types to use. Later, when we implement polymorphism, we'll use
    // a much better method with a vector of pointers instead.
    InventoryBin* pBin = nullptr;
    switch (binNumber)
    {
    case 1:
    {
        pBin = static_cast<ValveBin*>(pBin);
        pBin = &bin1;
        break;
    }
    case 2:
    {
        // TODO - remove the comments after implementing the classes
        pBin = static_cast<GearBin*>(pBin);
        pBin = &bin2;
        break;
    }
    case 3:
    {
        // TODO - remove the comments after implementing the classes
        pBin = static_cast<CableBin*>(pBin);
        pBin = &bin3;
        break;
    }
    case 4:
    {
        // TODO - remove the comments after implementing the classes
        pBin = static_cast<RodBin*>(pBin);
        pBin = &bin4;
        break;
    }
    }

    if (numParts < 0)
    {
        cout << "\n** Error: number of parts cannot be negative.\n";
    }
    else if (pBin != nullptr)
    {
        if (pBin->getNumParts() - numParts < 0)
        {
            cout << "\n** Error: you are attempting to remove more parts than the bin is holding.\n";
        }
        else
        {
            pBin->setNumParts(pBin->getNumParts() - numParts);
            success = true;
        }
    }

    return success;
}
