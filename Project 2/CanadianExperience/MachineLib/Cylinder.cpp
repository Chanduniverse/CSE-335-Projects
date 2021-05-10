/**
 * \file Cylinder.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "Cylinder.h"
#include "AirReceiver.h"
using namespace std;

CCylinder::CCylinder()
{
    mBase.SetImage(L"images/cylinder-base.png");
    mBase.Rectangle(-mBase.GetImageWidth() / 2, 0);
    mCylinder.SetImage(L"images/cylinder.png");
    mCylinder.Rectangle(-mCylinder.GetImageWidth() / 2, 0);
    mRam.SetImage(L"images/cylinder-ram.png");
    mRam.Rectangle(-mRam.GetImageWidth() / 2, 0);

    mReceiver = make_shared<CAirReceiver>();
    mReceiver->SetComponent(this);
}

void CCylinder::Draw(Gdiplus::Graphics* graphics, int X, int Y)
{
    mBase.SetRotation(mRotation);
    mRam.SetRotation(mRotation);
    mCylinder.SetRotation(mRotation);

    mBase.DrawPolygon(graphics, X + GetX(), Y + GetY());

    if (mRotation == 0.5)
        mRam.DrawPolygon(graphics, X + GetX(), Y + GetY() + (mRamPosition * mMaxExtent * 50));
    else if (mRotation == 0.25)
        mRam.DrawPolygon(graphics, X + GetX() + (mRamPosition * mMaxExtent * 50), Y + GetY());
    else
        mRam.DrawPolygon(graphics, X + GetX(), Y + GetY() - (mRamPosition * mMaxExtent * 50));

    mCylinder.DrawPolygon(graphics, X + GetX(), Y + GetY());

}

void CCylinder::OnAirPumped(double input)
{
    if (input > 0)
    {
        mRamPosition = 1;
        
    }
    else
    {
        mRamPosition = 0;
    }

    mMotionSink->OnMovement(input);
}