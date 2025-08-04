//
// GearBin.cpp : Implements the GearBin class.
//

#include <iostream>
#include "GearBin.h"

using namespace std;

//
// Default constructor
//
GearBin::GearBin()
{
    // Set default valve type
    gearSize = 'S';

    // Set this bin's part name
    partName = "Gear";

    // Set the maximum parts specific for this bin type:
    maxParts = 30;
}

//
// Parameterized constructor. Note the use of the initializer list to tell the
// compiler to invoke the base class parameterized constructor.
//
GearBin::GearBin(int num, char size)
    : InventoryBin(num)
{
    gearSize = size;

    // Set this bin's part name
    partName = "Gear";

    // Set the maximum parts specific to this bin type:
    maxParts = 30;
}

//
// Destructor
//
GearBin::~GearBin()
{

}

//
// This override of the base class function prints out additional information
// specific to this type of bin.
//
void GearBin::print()
{
    // First we call the base class version to let it do some of the work for us:
    InventoryBin::print();

    // Now add on our part:
    cout << endl << "    Gear Size: " << getSize() << endl;
}