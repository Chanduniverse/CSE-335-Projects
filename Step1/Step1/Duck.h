/**
 * \file Duck.h
 *
 * \author Chandan Aralikatti
 *
 * Declaration of the CDuck class.
 */

#pragma once

#include <string>
#include "Animal.h"
 /**
  * Class that describes a duck
  *
  */
class CDuck : public CAnimal
{
public:
    /// The types of ducks we can have on our farm
    enum class Type { MallardDuck, WoodDuck, DisneyDuck, WarnerBrothersDuck };

    /** Display an animal. */
    void DisplayAnimal();

    /** Obtain duck's name and type */
    void ObtainDuckInformation();

    /** Determine if witch-weight or not.
    * 
    * \returns bool based on witch-weight
    */
    bool IsWitchWeight();

private:
    /// The duck's name
    std::string mName;

    /// The type of Duck: MallardDuck, WoodDuck, DisneyDuck, WarnerBrothersDuck
    Type mType = Type::MallardDuck;

};