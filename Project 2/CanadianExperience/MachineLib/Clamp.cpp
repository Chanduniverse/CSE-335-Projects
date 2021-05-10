#include "pch.h"
#include "Clamp.h"

CClamp::CClamp(int x, int y, double rot, double speed)
{
	SetPos(x, y);
	SetRotation(rot);
	SetSpeed(speed);
}