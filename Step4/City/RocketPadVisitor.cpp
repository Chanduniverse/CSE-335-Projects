/**
 * \file RocketPadVisitor.cpp
 *
 * \author Chandan Aralikatti
 */


#include "pch.h"
#include "RocketPadVisitor.h"

 /** Visit a CTileRocketPad object
 * \param pad pad we are visiting */
void CRocketPadVisitor::VisitRocketPad(CTileRocketPad* pad)
{
    mNumPads++;
    if (pad->HasRocket())
    {
        mLaunchPad = pad;
        mRocket = pad->GetRocket();
    }
}