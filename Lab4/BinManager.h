//
// BinManager.h : Declares the BinManager class.
//

// Prevent multiple inclusion:
#ifndef BIN_MANAGER_H
#define BIN_MANAGER_H

#include "ValveBin.h"
// TODO - remove these comments after declaring and implementing these classes:
#include "GearBin.h"
#include "CableBin.h"
#include "RodBin.h"

class BinManager
{
public:
    // Constructor/destructor:
    BinManager();
    ~BinManager();

    bool updateBin(int binNumber);
    void print();

    // Accessor/mutator (inline)
    int getNumBins() const
    {
        return numBins;
    }

private:
    int numBins;
    ValveBin bin1;
    // TODO - remove these comments after declaring and implementing these classes:
    GearBin bin2;
    CableBin bin3;
    RodBin bin4;

    // Private helper functions:
    bool addParts(int binNumber, int numParts);
    bool removeParts(int binNumber, int numParts);
};

#endif // BIN_MANAGER_H