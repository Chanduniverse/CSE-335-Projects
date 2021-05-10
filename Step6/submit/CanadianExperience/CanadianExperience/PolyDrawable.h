/**
 * \file PolyDrawable.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once
#include "Drawable.h"
#include <vector>

 /**
  * A drawable based on polygon images.
  *
  * This class has a list of points and draws a polygon
  * drawable based on those points.
  */
class CPolyDrawable :
    public CDrawable
{
public:

    /** Default constructor disabled */
    CPolyDrawable() = delete;
    /** Copy constructor disabled */
    CPolyDrawable(const CPolyDrawable&) = delete;
    /** Assignment operator disabled */
    void operator=(const CPolyDrawable&) = delete;

    CPolyDrawable(const std::wstring& name);

    /** Set the color
    * \param c The new color */
    void SetColor(Gdiplus::Color c) { mColor = c; }

    /** Get the color
    * \returns The color*/
    Gdiplus::Color GetColor() const { return mColor; }

    virtual void Draw(Gdiplus::Graphics* graphics) override;
    virtual bool HitTest(Gdiplus::Point pos) override;

    /** Add point to the poly drawable
    * \param point to be added */
    void AddPoint(Gdiplus::Point point);

private:
    /// The polygon color
    Gdiplus::Color mColor = Gdiplus::Color::Black;

    /// The array of point objects
    std::vector<Gdiplus::Point> mPoints;
};

