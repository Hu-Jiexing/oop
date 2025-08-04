//
// InventoryBin.h : Declares the InventoryBin class.
//

// Prevent multiple inclusion:
#ifndef INVENTORY_BIN_H
#define INVENTORY_BIN_H

#include <string>
class InventoryBin
{
public:
    // Constructors:
    InventoryBin();
    InventoryBin(std::string name, int num);

    // Destructor
    ~InventoryBin();

    // Accessor/mutator (these are inline):
    std::string getPartName() const
    {
        // TODO - your code goes here
        return part;
    }
    int getNumParts() const
    {
        // TODO - your code goes here
        return quantity;
    }
    void setPartName(std::string name)
    {
        // TODO - your code goes here
        part = name;
    }
    void setNumParts(int num)
    {
        // TODO - your code goes here
        quantity = num;
    }

private:
    // TODO - your code goes here
    std::string part;
    int quantity;
};

#endif // INVENTORY_BIN_H