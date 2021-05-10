/**
 * \file AirSource.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once

/**
 * Class that represents an air source.
 */
class CAirSource
{
public:
	/** Air pumped
	 * \param output the air being pumped in */
	virtual void OnAirPumped(double output) = 0;
};

