/**
 * \file UnmaskedSpartyFactory.h
 *
 * \author Chandan Aralikatti
 *
 *  Factory class that builds the Unmasked Sparty character
 * 
 */

#pragma once
#include "ActorFactory.h"

/**
* Factory class that builds the Unmasked Sparty character
*/
class CUnmaskedSpartyFactory :
    public CActorFactory
{
public:
    virtual std::shared_ptr<CActor> CUnmaskedSpartyFactory::Create() override;
};

