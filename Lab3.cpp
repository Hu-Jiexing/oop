// 2202834_Jiexing_Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//
// main.cpp : Defines the entry point for the application.
//
// Inventory Bins - with Objects!
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>

// This brings in the declaration of our class:
#include "InventoryBin.h"

using namespace std;
char option;

// Function prototypes
void updateBin(vector<InventoryBin>&, int);
void addParts(InventoryBin&, int);
void removeParts(InventoryBin&, int);

int main()
{
    // Declare and intitialize a vector of InventoryBin objects.

    // TODO - your code goes here
    vector<InventoryBin> bin =
    {
          {"Valve", 10},
          {"Bearing", 5},
          {"Bushing", 15},
          {"Coupling", 21},
          {"Flange", 7},
          {"Gear", 5},
          {"Gear Housing", 5},
          {"Vacuum Gripper", 25},
          {"Cable", 18},
          {"Rod", 12}
    };
    InventoryBin b;

    int choice = 0;
    int modify = 0;

    // Loop, repeatedly displaying the Inventory Bin menu and letting the user
    // select bins to update, until the user enters 0.

    // TODO - your code goes here

    do {
        cout << "\n** Inventory Bins - with Classes **\n\n";
        for (int i = 0; i < 10; i++)
        {
            cout << "Bin # " << setw(3) << left << i + 1 << " ";
            cout << "Part: " << setw(20) << left << bin[i].getPartName();
            cout << setw(10) << left << "Quantity: ";
            cout << bin[i].getNumParts() << "\n";
        }

        cout << "\nEnter 0 to quit, or choose a bin Number: ";
        cin >> choice;

        if (choice != 0)
        {
            updateBin(bin, choice - 1);

            if (option == 'a' || option == 'A') {
                cout << "How many parts to add? ";
                cin >> modify;
                addParts(bin[choice - 1], modify);
            }

            else if (option == 'r' || option == 'R') {
                cout << "How many parts to remove? ";
                cin >> modify;
                removeParts(bin[choice - 1], modify);
            }
        }
    } while (choice != 0);

    return 0;
}

//*********************************************************
// Function updateBin                                     *
// This function lets the user choose whether to add or   *
// remove parts from the bin bins[Choice].                *
//*********************************************************
void updateBin(vector<InventoryBin>& bins, int choice)
{
    // Prompt the user for desired action (add or remove), validate
    // the input, and call the appropriate function to either add
    // parts or remove parts from the given bin.

    // TODO - your code goes here
    cout << "Add or Remove Parts (A or R)? ";
    cin >> option;
}

//***********************************************************
// Function addParts                                        *
// This function adds the value passed to numAdd to the     *
// num member of the bin structure. The value is validated. *
//***********************************************************
void addParts(InventoryBin& bin, int numAdd)
{
    // Validate the number of parts and add them if the number
    // is valid. Don't allow the user to add more than 30
    // parts to a bin.

    // TODO - your code goes here
    if (bin.getNumParts() + numAdd > 30) {
        cout << "\n** Error: the bin can only hold 30 parts\n";
    }
    else {
        bin.setNumParts(bin.getNumParts() + numAdd);
        cout << "\n** Success: parts were added to the bin.\n";
    }
}

//************************************************************
// Function removeParts                                      *
// This function subtracts the value passed to numRem to the *
// num member of the bin structure. The value is validated.  *
//************************************************************
void removeParts(InventoryBin& bin, int numRem)
{
    // Validate the number of parts and remove them if the number
    // is valid. Don't allow the user to remove more parts than
    // the bin contains.

    // TODO - your code goes here
    if (bin.getNumParts() - numRem < 0) {
        cout << "\n** Error: There is less than " << numRem << " parts to remove\n";
    }
    else {
        bin.setNumParts(bin.getNumParts() - numRem);
        cout << "\n** Success: parts were removed from the bin.\n";
    }
}