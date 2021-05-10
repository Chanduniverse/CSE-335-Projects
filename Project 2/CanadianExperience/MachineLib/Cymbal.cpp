/**
 * \file Cymbal.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "Cymbal.h"
#include <math.h> 

#define PI 3.14159265 ///< pi

CCymbal::CCymbal()
{
    mCymbal.SetImage(L"images/cymbal.png");
    mCymbal.Rectangle(-mCymbal.GetImageWidth() / 2, 0);
    mStand.SetImage(L"images/cymbal-stand.png");
    mStand.Rectangle(-mStand.GetImageWidth() / 2, 0);

}

void CCymbal::Draw(Gdiplus::Graphics* graphics, int X, int Y)
{
    mCymbal.SetRotation(mVibration);
    
    mStand.DrawPolygon(graphics, X + GetX(), Y + GetY());
    mCymbal.DrawPolygon(graphics, X + GetX(), Y + GetY() - mStand.GetImageHeight() + 40);

}

void CCymbal:: SetTime(double time) 
{
    if (IsInstrumentHit())
    {
        mVibration = 0.02*(0.9 / (1 + (-mHitTime + time)) * cos(2 * PI * (-mHitTime + time)));
    }
    else
    {
        
        if (mVibration > 0.00 && !(abs(mVibration) < 0.001))
        {
            mVibration = 0.02 * (0.9 / (1 + (-mHitTime + time)) * cos(2 * PI * (-mHitTime + time)));
        }
        else
        {
            mHitTime = time;
            mVibration = 0;
        }
        
    }
    
};