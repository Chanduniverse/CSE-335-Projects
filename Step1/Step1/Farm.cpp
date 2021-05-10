/**
 * \file Farm.cpp
 *
 * \author Chandan Aralikatti
 * 
 * Class that describes a Farm.
 *
 * This class holds a collection of animals that make
 * up the inventory of a farm.
 */

#include "Farm.h"
#include "leak.h"

 /**
  * CFarm destructor
  */
CFarm::~CFarm()
{
    // Iterate over all of the animals, destroying 
    // each one.
    for (auto animal : mInventory)
    {
        delete animal;
    }

    // And clear the list
    mInventory.clear();
}

/** Add an animal to the farm inventory.
 *
 * \param animal to add to the inventory
 */
void CFarm::AddAnimal(CAnimal* animal)
{
    mInventory.push_back(animal);
}

/**
 * Display the farm inventory.
 */
void CFarm::DisplayInventory()
{
    for (auto animal : mInventory)
    {
        animal->DisplayAnimal();
    }
}


/**
 * Determine number of witch-weight animals in the farm.
 * 
 * loop through mInventory and check if animal is witch-weight
 * 
 * \return Number of witch-weight animals
 */
int CFarm::NumOfWitchWeight()
{
    int num = 0;
    for (auto i : mInventory)
    {
        if (i->IsWitchWeight())
            num++;
    }
    return num;
}

