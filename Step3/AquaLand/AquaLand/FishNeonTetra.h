/**
 * \file FishNeonTetra.h
 *
 * \author Chandan Aralikatti
 *
 * Class that implements a Neon tetra fish
 */

#pragma once
#include "Fish.h"
#include<memory>

 /**
  * Implements a Neon tetra fish.
  */
class CFishNeonTetra : public CFish
{
public:
    CFishNeonTetra(CAquarium* aquarium);

    /// Default constructor (disabled)
    CFishNeonTetra() = delete;

    /// Copy constructor (disabled)
    CFishNeonTetra(const CFishNeonTetra&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

};

