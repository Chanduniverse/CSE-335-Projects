/**
 * \file AnimChannelPosition.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "AnimChannelPosition.h"

using namespace std;
using namespace Gdiplus;

/**
* Set a keyframe
*
* This function allocates a new keyframe and sends it to
* CAnimChannel, which will insert it into the collection of keyframes.
* \param point Point for the keyframe.
*/
void CAnimChannelPosition::SetKeyframe(Gdiplus::Point point)
{
    // Create a keyframe of the appropriate type
    // Telling it this channel and the angle
    shared_ptr<KeyframeDistance> keyframe =
        make_shared<KeyframeDistance>(this, point);

    // Insert it into the collection
    InsertKeyframe(keyframe);
}

/**
 * Compute an angle that is an interpolation between two keyframes
 *
 * This function is called after Use1 and Use2, so we have pointers to
 * to valid keyframes of the type KeyframeAngle. This function does the
 * tweening.
 * \param t A t value. t=0 means keyframe1, t=1 means keyframe2. Other values
 * interpolate between.
 */
void CAnimChannelPosition::Tween(double t)
{
    mPoint = Point(int(mKeyframe1->GetPoint().X + t * (mKeyframe2->GetPoint().X - mKeyframe1->GetPoint().X)), int(mKeyframe1->GetPoint().Y + t * (mKeyframe2->GetPoint().Y - mKeyframe1->GetPoint().Y)));
}