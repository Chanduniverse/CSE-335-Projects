/**
 * \file ChooseRocketPadVisitor.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "ChooseRocketPadVisitor.h"

/** Visit a CChooseRocketPadVisitor object
* \param pad pad we are visiting */
void CChooseRocketPadVisitor::VisitRocketPad(CTileRocketPad* pad)
{
	if (!pad->HasRocket())
	{
		mChosenPad = pad;
	}
}