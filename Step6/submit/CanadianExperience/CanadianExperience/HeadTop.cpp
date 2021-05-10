/**
 * \file HeadTop.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "HeadTop.h"
#include "Timeline.h"

using namespace Gdiplus;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

/** Constructor
  * \param name The drawable name
  * \param filename The filename for the image */
CHeadTop::CHeadTop(const std::wstring& name, const std::wstring& filename) :
    CImageDrawable(name, filename)
{
   
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

void CHeadTop::Draw(Gdiplus::Graphics* graphics)
{
    CImageDrawable::Draw(graphics);

    Pen pen(Color::Black, 2);
    graphics->DrawLine(&pen, TransformPoint(mRightEyebrow1), TransformPoint(mRightEyebrow2));
    graphics->DrawLine(&pen, TransformPoint(mLeftEyebrow1), TransformPoint(mLeftEyebrow2));

    float wid = 15.0f;
    float hit = 20.0f;

    SolidBrush* brush = new SolidBrush(Color::Black);

    auto state = graphics->Save();
    auto left = TransformPoint(mLeftEye);
    graphics->TranslateTransform(left.X, left.Y);
    graphics->RotateTransform((float)(-mPlacedR * RtoD));
    graphics->FillEllipse(brush, -wid / 2, -hit / 2, wid, hit);
    graphics->Restore(state);

    state = graphics->Save();
    auto right = TransformPoint(mRightEye);
    graphics->TranslateTransform(right.X, right.Y);
    graphics->RotateTransform((float)(-mPlacedR * RtoD));
    graphics->FillEllipse(brush, -wid / 2, -hit / 2, wid, hit);
    graphics->Restore(state);

}

/** Set the keyframe based on the current status.
*/
void CHeadTop::SetKeyframe()
{
    mChannel.SetKeyframe(GetPosition());
    CDrawable::SetKeyframe();
}

/** Get the current channel from the animation system.
*/
void CHeadTop::GetKeyframe()
{
    if (mChannel.IsValid())
        SetPosition(mChannel.GetPoint());
    CDrawable::GetKeyframe();
}

/** Delete the keyframe based on the current status.
*/
void CHeadTop::DeleteKeyframe()
{
    mChannel.DeleteKeyframe();
    CDrawable::DeleteKeyframe();
}

/** Add the channels for this drawable to a timeline
 * \param timeline The timeline class.
 */
void CHeadTop::SetTimeline(CTimeline* timeline)
{
    timeline->AddChannel(&mChannel);
    CDrawable::SetTimeline(timeline);
}