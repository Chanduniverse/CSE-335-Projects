/**
 * \file Farm.h
 *
 * \author Chandan Aralikatti
 *
 * Declaration of the CFarm class.
 */

#pragma once

#include <vector>
#include "Cow.h"

/**
 * Class that describes a farm
 * 
 * Holds a collection of animals that make up the farm inventory.
 */
class CFarm
{
public:
    ~CFarm();

    /** Display an animals. */
    void DisplayInventory();

    /** Add animal to the farm */
    void AddAnimal(CAnimal* animal);

    /** Determines number of witch-weight animals.
    *
    * \returns Number of witch-weight animals
    */
    int NumOfWitchWeight();

private:
    /// A list with the inventory of all animals on the farm
    std::vector<CAnimal*> mInventory;
};

