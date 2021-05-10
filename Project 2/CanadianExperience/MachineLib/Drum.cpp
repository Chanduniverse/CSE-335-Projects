/**
 * \file Drum.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "Drum.h"

CDrum::CDrum()
{
    mDrum.SetImage(L"images/drum.png");
    mDrum.Rectangle(-mDrum.GetImageWidth() / 2, 0);

}

void CDrum::Draw(Gdiplus::Graphics* graphics, int X, int Y)
{



    mDrum.DrawPolygon(graphics, X + GetX(), Y + GetY());


}