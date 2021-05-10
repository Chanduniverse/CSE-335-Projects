/**
 * \file AirSink.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once

/**
 * Class that represents an air sink.
 */
class CAirSink
{
public:
	/** Air pumped
	 * \param input the air being pumped in */
	virtual void OnAirPumped(double input) = 0;
};

