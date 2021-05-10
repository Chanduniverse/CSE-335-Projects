/**
 * \file Chime.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "Chime.h"

/// The chime hammer mount image
const std::wstring ChimeMountImage = L"images/hammer-mount.png";

/// The chime hammer image
const std::wstring ChimeHammerImage = L"images/hammer.png";

/// The chime itself
const std::wstring ChimeImage = L"images/chime.png";

/// Width to draw the actual chime
const int ChimeWidth = 15;

/// Offset of the Chime relative to the origin
/// of this component X value
const double ChimeOffsetX = -18.0;

/// Offset of the Chime Y value
const double ChimeOffsetY = 5.0;

/// The location in the hammer image for the pivot point X
const double HammerPivotX = 33;

/// The location in the hammer image for the pivot point X
const double HammerPivotY = 10;

/// Amount to rotate hammer away from chime in unit rotations
const double HammerRotation = 0.08;

CChime::CChime(int length)
{
    mMount.SetImage(ChimeMountImage);
    mMount.Rectangle(-mMount.GetImageWidth() / 2, mMount.GetImageHeight());

    mHammer.SetImage(ChimeHammerImage);
    mHammer.Rectangle(-HammerPivotX, HammerPivotY);

    mTube.SetImage(ChimeImage);
    mTube.Rectangle(-ChimeWidth / 2, 0, ChimeWidth, -length);

}

void CChime::Draw(Gdiplus::Graphics* graphics, int X, int Y)
{



    mTube.DrawPolygon(graphics, X + GetX() - 20, Y + GetY());

    mMount.DrawPolygon(graphics, X + GetX(), Y + GetY());

    if (!IsInstrumentHit())
    {
        mHammer.SetRotation(HammerRotation);
    }
    else
    {
        mHammer.SetRotation(0);
    }
    

    mHammer.DrawPolygon(graphics, X + GetX(), Y + GetY() + mMount.GetImageHeight() - 10);

}

