//
// CableBin.h : Declares the CableBin class.
//

// Prevent multiple inclusion:
#ifndef CABLE_BIN_H
#define CABLE_BIN_H

#include <string>
#include "InventoryBin.h"

class CableBin : public InventoryBin
{
public:
    // Constructors:
    CableBin();
    CableBin(int num, std::string colour);

    // Destructor
    ~CableBin();

    // This function prints out the bin information and must be
    // overridden (redefined) in child classes:
    void print();

    // Accessor/mutator (these are inline):
    std::string getColor() const
    {
        return cableColor;
    }
    void setColor(std::string colour)
    {
        cableColor = colour;
    }

private:
    std::string cableColor;
};

#endif // CABLE_BIN_H