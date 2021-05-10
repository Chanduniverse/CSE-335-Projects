/**
 * \file HaroldFactory.h
 *
 * \author Chandan Aralikatti
 *
 * Factory class that builds the Harold character 
 * 
 */

#pragma once
#include "ActorFactory.h"

/**
* Factory class that builds the Harold character
*/
class CHaroldFactory :
    public CActorFactory
{
public:
    virtual std::shared_ptr<CActor> CHaroldFactory::Create() override;

};

