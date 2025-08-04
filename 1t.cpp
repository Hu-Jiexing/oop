//
// main.cpp : Defines the entry point for the application.
//
// Adapted from the textbook: "Starting Out with C++: From Control Structures Through
// Objects", 9th Ed,  Chapter 11, Programming Challenge 14: Inventory Bins
// 
// Modified for use in EDE2012 Object Oriented Programming
// Singapore Institute of Technology & Technical University of Munich
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

// No, this is NOT "bad practice" despite what you read on Stack Overflow.
// Just don't put it in a header (.h) file.
using namespace std;

// Constants for array size
static const int NUM_BINS = 10;
char option;
int modify = 0;

// Declaration of the InventoryBin structure
struct InventoryBin
{
    // TODO - enter your code here (hint: use the C++ string object for the description)
    string description;
    int number;
};

// Function prototypes
void updateBin(InventoryBin[], int);
void addParts(InventoryBin&, int);
void removeParts(InventoryBin&, int);

int main()
{
    // The user's menu choice
    int choice = 0;

    // Declare and intitialize an array of InventoryBin structures. For this
    // exercise, we'll use a standard 'C' style array but take advantage of
    // the C++ initializer list to set the initial values of the structures.

    InventoryBin bins[NUM_BINS] =
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

    do
    {  
        // Display the contents of each bin as a menu.
        // TODO - enter your code here

        for (int i = 0; i < 10; i++)
        {
            cout << "Bin # " << setw(3) << left << i + 1 << " ";
            cout << "Part: " << setw(20) << left << bins[i].description;
            cout << setw(10) << left << "Quantity: " << bins[i].number << "\n";
        }

        cout << "Enter 0 to quit, or choose a bin Number: ";
        cin >> choice;

        if (choice != 0)
        {
            updateBin(&bins[choice - 1], choice - 1);

            if (option == 'a' || option == 'A') {
                cout << "How many parts to add? ";
                cin >> modify;
                addParts(bins[choice-1], modify);
            }
            
            else if (option == 'r' || option == 'R') {
                cout << "How many parts to remove? ";
                cin >> modify;
                removeParts(bins[choice-1], modify);
            }
        }
    } while (choice != 0);

    return 0;
}

//*********************************************************
// Function updateBin                                     *
// This function lets the user choose whether to add or   *
// remove parts from the bin bins[Choice].                   *
//*********************************************************
void updateBin(InventoryBin bins[], int choice)
{
    // TODO - enter your code here

    cout << "Add or Remove Parts (A or R)? ";
    cin >> option;
}

//***********************************************************
// Function addParts                                        *
// This function adds the value passed to numAdd to the     *
// num member of the bin structure. The value is validated. *
//                                                          *
// Note the use of the C++ reference type to pass the       *
// InventoryBin structure to the function.                  *
//***********************************************************
void addParts(InventoryBin& bin, int numAdd)
{
    // Validate the number of parts and add them
    // if the number is valid.
    // TODO - enter your code here

    if (bin.number + numAdd > 30) {
        cout << "** Error: the bin can only hold 30 parts\n";
    }
    else {
        bin.number += numAdd;
    }
}

//************************************************************
// Function removeParts                                      *
// This function subtracts the value passed to numRem to the *
// num member of the bin structure. The value is validated.  *
//                                                           *
// Note the use of the C++ reference type to pass the        *
// InventoryBin structure to the function.                   *
//************************************************************
void removeParts(InventoryBin& bin, int numRem)
{
    // Validate the number of parts and remove them
    // if the number is valid.

    // TODO - enter your code here

    if (bin.number - numRem < 0) {
        cout << "** Error: There is less than " << numRem << " parts to remove\n";
    }

    else {
        bin.number -= numRem;
    }
}