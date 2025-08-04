//
// InventoryBin.cpp : Implements the InventoryBin class.
//

#include "InventoryBin.h"

using namespace std;

//
// Default constructor
//
InventoryBin::InventoryBin()
{
    // TODO - your code goes here  
    part = "";
    quantity = 0;
}

//
// Parameterized constructor
//
InventoryBin::InventoryBin(string name, int num)
{
    // TODO - your code goes here
    part = name;
    quantity = num;
}

//
// Destructor
//
InventoryBin::~InventoryBin()
{

}