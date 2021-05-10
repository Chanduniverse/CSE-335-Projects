/**
 * \file ActorFactory.h
 *
 * \author Chandan Aralikatti
 *
 * Abstract base class for actor factories. 
 * 
 */

#pragma once
#include <memory>
#include "Actor.h"
/**
* Abstract base class for actor factories.
*/
class CActorFactory
{
public:
	/** Creates the actor
	* \return The actor
	*/
	virtual std::shared_ptr<CActor> Create() = 0;
};

