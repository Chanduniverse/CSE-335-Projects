/**
 * \file HeadTop.h
 *
 * \author Chandan Aralikatti
 *
 * Class that handles the top of the head
 */

#pragma once
#include "ImageDrawable.h"

/**
* 
* Class that handles the top of the head
* 
*/
class CHeadTop :
    public CImageDrawable
{
public:
    CHeadTop(const std::wstring& name, const std::wstring& filename);

    /** checks wether drawable can be moved or not
    * \return true if drawable is movable
    */
    virtual bool IsMovable() override { return true; }

    /**
     * Draw the image drawable
     * \param graphics Graphics context to draw on
     */
    virtual void Draw(Gdiplus::Graphics* graphics);

    Gdiplus::Point TransformPoint(Gdiplus::Point p);

    /**
     * Set the right eyebrow
     * \param one Point one of eyebrow
     * \param two Point two of eyebrow
     */
    void SetRightEyebrow(Gdiplus::Point one, Gdiplus::Point two) { mRightEyebrow1 = one, mRightEyebrow2 = two; };

    /**
     * Set the left eyebrow
     * \param one Point one of eyebrow
     * \param two Point two of eyebrow
     */
    void SetLeftEyebrow(Gdiplus::Point one, Gdiplus::Point two) { mLeftEyebrow1 = one, mLeftEyebrow2 = two; };

    /**
     * Set the eyes
     * \param one Center of left eye
     * \param two Center of right eye
     */
    void SetEyes(Gdiplus::Point one, Gdiplus::Point two) { mLeftEye = one, mRightEye = two; };

    virtual void SetKeyframe();

    virtual void GetKeyframe();

    virtual void DeleteKeyframe() override;

    virtual void SetTimeline(CTimeline* timeline);

private:
    Gdiplus::Point mRightEyebrow1 = Gdiplus::Point(0,0); ///< point one of right eyebrow
    Gdiplus::Point mRightEyebrow2 = Gdiplus::Point(0, 0); ///< point two of right eyebrow

    Gdiplus::Point mLeftEyebrow1 = Gdiplus::Point(0, 0); ///< point one of left eyebrow
    Gdiplus::Point mLeftEyebrow2 = Gdiplus::Point(0, 0); ///< point two of right eyebrow

    Gdiplus::Point mRightEye = Gdiplus::Point(0, 0); ///< Center of right eye
    Gdiplus::Point mLeftEye = Gdiplus::Point(0, 0); ///< Center of left eye

    /// The animation channel for animating the position of this drawable
    CAnimChannelPosition mChannel;
};

