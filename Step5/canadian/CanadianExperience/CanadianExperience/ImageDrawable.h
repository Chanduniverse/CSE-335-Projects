/**
 * \file ImageDrawable.h
 *
 * \author Chandan Aralikatti
 *
 * Class that handles images that are drawables
 * 
 */

#pragma once
#include "Drawable.h"
#include <memory>


/**
* Class that handles images that are drawables
* 
*/
class CImageDrawable :
    public CDrawable
{
public:
    /** Set the drawable center
     * \param pos The new drawable center*/
    void SetCenter(Gdiplus::Point pos) { mCenter = pos; }

    /** Get the drawable position
     * \returns The drawable position*/
    Gdiplus::Point GetCenter() const { return mCenter; }

    CImageDrawable(const std::wstring& name, const std::wstring& filename);

    virtual bool HitTest(Gdiplus::Point pos) override;

    virtual void Draw(Gdiplus::Graphics* graphics) override;

private:
    /// The image for this drawable
    std::unique_ptr<Gdiplus::Bitmap> mImage;

    /// The center of this drawable relative to its parent
    Gdiplus::Point mCenter = Gdiplus::Point(0, 0);
};

