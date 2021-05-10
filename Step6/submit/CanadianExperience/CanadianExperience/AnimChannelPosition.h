/**
 * \file AnimChannelPosition.h
 *
 * \author Chandan Aralikatti
 *
 * Class that animates positons
 */

#pragma once
#include "AnimChannel.h"

 /**
 * Animation channel for positions.
 */
class CAnimChannelPosition :
    public CAnimChannel
{
public:
    CAnimChannelPosition() {};
    /** Copy constructor disabled */
    CAnimChannelPosition(const CAnimChannelPosition&) = delete;
    /** Assignment operator disabled */
    void operator=(const CAnimChannelPosition&) = delete;

    /** Get the point
     * \returns point */
    Gdiplus::Point GetPoint() const { return mPoint; }

    /** Class that represents a keyframe */
    class KeyframeDistance : public Keyframe
    {
    public:
        /** Default constructor disabled */
        KeyframeDistance() = delete;
        /** Copy constructor disabled */
        KeyframeDistance(const KeyframeDistance&) = delete;
        /** Assignment operator disabled */
        void operator=(const KeyframeDistance&) = delete;

        /** Constructor
         * \param channel The channel we are for
         * \param point The point for the keyframe */
        KeyframeDistance(CAnimChannelPosition* channel, Gdiplus::Point point) :
            Keyframe(channel), mChannel(channel), mPoint(point) {}

        /** Get the angle
        * \returns angle */
        Gdiplus::Point GetPoint() const { return mPoint; }

        /** Use this keyframe as keyframe 1 */
        virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

        /** Use this keyframe as keyfraem 2 */
        virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

        /** Use this keyframe as the angle */
        virtual void UseOnly() override { mChannel->mPoint = mPoint; }

    private:
        Gdiplus::Point mPoint; ///< point of keyframe

        /// The channel this keyframe is associated with
        CAnimChannelPosition* mChannel;
    };

    void SetKeyframe(Gdiplus::Point point);

    virtual void Tween(double t) override;

private:
    Gdiplus::Point mPoint; ///< point at a frame

    /// The first angle keyframe
    KeyframeDistance* mKeyframe1 = nullptr;

    /// The second angle keyframe
    KeyframeDistance* mKeyframe2 = nullptr;
};

