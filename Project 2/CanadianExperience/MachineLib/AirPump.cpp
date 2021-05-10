/**
 * \file AirPump.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "AirPump.h"
#include "AirReceiver.h"
void CAirPump::OnAirPumped(double output) 
{ 
	mOutput = output;
	mReceiver->OnAirPumped(mOutput); 
	SetSpeed(output + GetMinSpeed());
}
