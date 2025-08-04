//
// RodBin.h : Declares the RodBin class.
//

// Prevent multiple inclusion:
#ifndef ROD_BIN_H
#define ROD_BIN_H

#include <string>
#include "InventoryBin.h"

class RodBin : public InventoryBin
{
public:
    // Constructors:
    RodBin();
    RodBin(int num, int length);

    // Destructor
    ~RodBin();

    // This function prints out the bin information and must be
    // overridden (redefined) in child classes:
    void print();

    // Accessor/mutator (these are inline):
    int getLength() const
    {
        return rodLength;
    }
    void setLength(int length)
    {
        rodLength = length;
    }

private:
    int rodLength;
};

#endif // ROD_BIN_H