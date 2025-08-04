// 2202834_Jiexing_Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.

//
// main.cpp : Defines the entry point for the application.
//
// Adapted from the textbook: "Starting Out with C++: From Control Structures Through Objects,
// Global/9th Ed" Chapter 11, Programming Challenge 14: Inventory Bins. This version uses a
// vector instead of an array to store the collection of structs.
// 
// Modified for use in EDE2012 Object Oriented Programming
// Singapore Institute of Technology & Technical University of Munich
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

char option;

// Declaration of the InventoryBin structure
struct InventoryBin
{
    // TODO - your code goes here - you need a string for
    // the part description and an integer for the number of parts.
    string parts;
    int number;
};

// Function prototypes
void updateBin(vector<InventoryBin>&, int);
void addParts(InventoryBin&, int);
void removeParts(InventoryBin&, int);

int main()
{
    // Declare and intitialize a collection of InventoryBin structures. For this
    // exercise, we'll use a vector from the C++ Standard Template Library (STL)
    // instead of an array.

    // TIP: with C++ 11, you can use an initializer list with a vector,
    // just like with arrays.
    vector<InventoryBin> bins =
    {
        // TODO - your code goes here
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

    // Loop, repeatedly displaying the Inventory Bin menu and letting the user
    // select bins to update, until the user enters 0.

    // TODO - your code goes here

    int choice = 0;
    int count;
    int modify = 0;

    do
    {
        // Display the contents of each bin as a menu.
        // TODO - enter your code here
        count = 0;
        cout << "\n** Inventory Bins - with Vector **\n\n";
        
        //use auto for complicated data types (instead of vector<InventoryBin>::iterator::value_type)

        for (vector<InventoryBin>::iterator::value_type &a: bins)
        {
            count++;
            cout << "Bin # " << setw(3) << left << count << " ";
            cout << "Part: " << setw(20) << left << a.parts ;
            cout << setw(10) << left << "Quantity: " << a.number << "\n";
        }
        cout << "\nEnter 0 to quit, or choose a bin Number: ";
        cin >> choice;

        if (choice != 0)
        {
            updateBin(bins, choice-1);

            if (option == 'a' || option == 'A') {
                cout << "How many parts to add? ";
                cin >> modify;
                addParts(bins[choice - 1], modify);
            }

            else if (option == 'r' || option == 'R') {
                cout << "How many parts to remove? ";
                cin >> modify;
                removeParts(bins[choice - 1], modify);
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
    if (bin.number + numAdd > 30) {
        cout << "\n** Error: the bin can only hold 30 parts\n";
    }
    else {
        bin.number += numAdd;
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
    if (bin.number - numRem < 0) {
        cout << "\n** Error: There is less than " << numRem << " parts to remove\n";
    }

    else {
        bin.number -= numRem;
        cout << "\n** Success: parts were removed from the bin.\n";
    }
}