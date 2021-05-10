/**
 * \file AirReceiver.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "AirReceiver.h"
#include "AirPump.h"
void CAirReceiver::OnAirPumped(double input) 
{
	mInput = input;
	if (mMainComponent != nullptr) 
		mMainComponent->OnAirPumped(mInput); 
	else mAirPump->OnAirPumped(input); 
	SetSpeed(input + GetMinSpeed());
}