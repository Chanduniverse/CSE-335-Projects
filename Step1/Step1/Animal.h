/**
 * \file Animal.h
 *
 * \author Chandan Aralikatti
 *
 * Declaration of the CAnimal class.
 */

#pragma once

/**
 * Class that describes a Animal.
 */
class CAnimal
{
public:
	virtual ~CAnimal();

	/** Display an animal. */
	virtual void DisplayAnimal() {}

	/** Determine if witch-weight or not.
	*
	* \returns bool based on witch-weight
	*/
	virtual bool IsWitchWeight() 
	{
		return false;
	}
};

