//
// RodBin.cpp : Implements the RodBin class.
//

#include <iostream>
#include "RodBin.h"

using namespace std;

//
// Default constructor
//
RodBin::RodBin()
{
    // Set default valve type
    rodLength = 1;

    // Set this bin's part name
    partName = "Rod";

    // Set the maximum parts specific for this bin type:
    maxParts = 30;
}

//
// Parameterized constructor. Note the use of the initializer list to tell the
// compiler to invoke the base class parameterized constructor.
//
RodBin::RodBin(int num, int length)
    : InventoryBin(num)
{
    rodLength = length;

    // Set this bin's part name
    partName = "Rod";

    // Set the maximum parts specific to this bin type:
    maxParts = 30;
}

//
// Destructor
//
RodBin::~RodBin()
{

}

//
// This override of the base class function prints out additional information
// specific to this type of bin.
//
void RodBin::print()
{
    // First we call the base class version to let it do some of the work for us:
    InventoryBin::print();

    // Now add on our part:
    cout << endl << "    Rod Length: " << getLength() << endl;
}