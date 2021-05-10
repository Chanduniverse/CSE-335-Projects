/**
 * \file AnimChannelAngle.h
 *
 * \author Chandan Aralikatti
 *
 * Animation channel for angles.
 * 
 */

#pragma once
#include "AnimChannel.h"

/**
* Animation channel for angles.
*/
class CAnimChannelAngle :
    public CAnimChannel
{
public:
    CAnimChannelAngle() {};
    /** Copy constructor disabled */
    CAnimChannelAngle(const CAnimChannelAngle&) = delete;
    /** Assignment operator disabled */
    void operator=(const CAnimChannelAngle&) = delete;

    /** Get the angle
     * \returns angle */
    double GetAngle() const { return mAngle; }

    /** Class that represents a keyframe */
    class KeyframeAngle : public Keyframe
    {
    public:
        /** Default constructor disabled */
        KeyframeAngle() = delete;
        /** Copy constructor disabled */
        KeyframeAngle(const KeyframeAngle&) = delete;
        /** Assignment operator disabled */
        void operator=(const KeyframeAngle&) = delete;

        /** Constructor
         * \param channel The channel we are for
         * \param angle The angle for the keyframe */
        KeyframeAngle(CAnimChannelAngle* channel, double angle) :
            Keyframe(channel), mChannel(channel), mAngle(angle) {}

        /** Get the angle
        * \returns angle */
        double GetAngle() const { return mAngle; }

        /** Use this keyframe as keyframe 1 */
        virtual void UseAs1() override { mChannel->mKeyframe1 = this; }

        /** Use this keyframe as keyfraem 2 */
        virtual void UseAs2() override { mChannel->mKeyframe2 = this; }

        /** Use this keyframe as the angle */
        virtual void UseOnly() override { mChannel->mAngle = mAngle; }

    private:
        double mAngle; ///< angle of keyframe

        /// The channel this keyframe is associated with
        CAnimChannelAngle* mChannel;
    };

    void SetKeyframe(double angle);


    virtual void Tween(double t) override;

private:
    double mAngle = 0; ///< angle at a frame

    /// The first angle keyframe
    KeyframeAngle* mKeyframe1 = nullptr;

    /// The second angle keyframe
    KeyframeAngle* mKeyframe2 = nullptr;
};

