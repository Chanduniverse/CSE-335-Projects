/**
 * \file RocketPadTileVisitor.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "RocketPadTileVisitor.h"

/** Visit a CTileRocketPad object
* \param pad pad we are visiting */
void CRocketPadTileVisitor::VisitRocketPad(CTileRocketPad* pad)
{
    mIsRocketPad = true;
    mLandingPad = pad;
}