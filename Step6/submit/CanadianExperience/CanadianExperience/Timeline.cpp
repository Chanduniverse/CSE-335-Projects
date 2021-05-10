/**
 * \file Timeline.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "Timeline.h"
#include "AnimChannel.h"

/**
* Constructor
*/
CTimeline::CTimeline()
{
}

/** Add channel to the timeline
*
* \param channel to be added
*/
void CTimeline::AddChannel(CAnimChannel* channel)
{
    mChannels.push_back(channel);
    channel->SetTimeline(this);
}

/** Sets the current time
*
* Ensures all of the channels are
* valid for that point in time.
* 
* \param currentTime
*/
void CTimeline::SetTime(double currentTime)
{
    // Set the time
    mCurrentTime = currentTime;

    for (auto channel : mChannels)
    {
        channel->SetFrame(GetCurrentFrame());
    }
}