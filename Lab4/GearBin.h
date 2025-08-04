#pragma once
//
// GearBin.h : Declares the GearBin class.
//

// Prevent multiple inclusion:
#ifndef GEAR_BIN_H
#define GEAR_BIN_H

#include <string>
#include "InventoryBin.h"

class GearBin : public InventoryBin
{
public:
    // Constructors:
    GearBin();
    GearBin(int num, char size);

    // Destructor
    ~GearBin();

    // This function prints out the bin information and must be
    // overridden (redefined) in child classes:
    void print();

    // Accessor/mutator (these are inline):
    char getSize() const
    {
        return gearSize;
    }
    void setSize(char size)
    {
        gearSize = size;
    }

private:
    char gearSize;
};

#endif // GEAR_BIN_H