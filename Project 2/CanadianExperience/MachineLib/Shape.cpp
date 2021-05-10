/**
 * \file Shape.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "Shape.h"

void CShape::Draw(Gdiplus::Graphics* graphics, int X, int Y)
{

    mPolygon.DrawPolygon(graphics, X + GetX(), Y + GetY());

}