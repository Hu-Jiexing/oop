//
// CableBin.cpp : Implements the CableBin class.
//

#include <iostream>
#include "CableBin.h"

using namespace std;

//
// Default constructor
//
CableBin::CableBin()
{
    // Set default valve type
    cableColor = "Ball Valve";

    // Set this bin's part name
    partName = "Cable";

    // Set the maximum parts specific for this bin type:
    maxParts = 30;
}

//
// Parameterized constructor. Note the use of the initializer list to tell the
// compiler to invoke the base class parameterized constructor.
//
CableBin::CableBin(int num, string colour)
    : InventoryBin(num)
{
    cableColor = colour;

    // Set this bin's part name
    partName = "Cable";

    // Set the maximum parts specific to this bin type:
    maxParts = 30;
}

//
// Destructor
//
CableBin::~CableBin()
{

}

//
// This override of the base class function prints out additional information
// specific to this type of bin.
//
void CableBin::print()
{
    // First we call the base class version to let it do some of the work for us:
    InventoryBin::print();

    // Now add on our part:
    cout << endl << "    Cable Color: " << getColor() << endl;
}