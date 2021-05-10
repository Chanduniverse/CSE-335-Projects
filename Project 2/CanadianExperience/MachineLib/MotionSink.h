/**
 * \file MotionSink.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once

/**
 * Class that represents an actual machine.
 */

class CMotionSink
{
public:
	/** On Movement
	 * \param force */
	virtual void OnMovement(double force) = 0;
};