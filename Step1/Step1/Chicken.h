/**
 * \file Chicken.h
 *
 * \author Chandan Aralikatti
 *
 * Declaration of the CChicken class.
 */

#pragma once

#include <string>
#include "Animal.h"

 /** Class that describes a chicken.
 */
class CChicken : public CAnimal
{
public:
    /** Obtains name of chicken. */
    void ObtainChickenInformation();

    /** Display an animal. */
    void DisplayAnimal();

private:
    //! The chicken's ID
    std::string mId;
};

