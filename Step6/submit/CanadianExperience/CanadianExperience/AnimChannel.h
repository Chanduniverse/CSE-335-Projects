/**
 * \file AnimChannel.h
 *
 * \author Chandan Aralikatti
 * 
 * Base class for animation channels 
 *
 * This class provides basic functionality and a polymorphic
 * representation for animation channels. 
 * 
 */

#pragma once
#include <string>
#include <memory>
#include <vector>

class CTimeline;

/**
* Base class for animation channels
*
* This class provides basic functionality and a polymorphic
* representation for animation channels.
*/
class CAnimChannel
{
public:
	virtual ~CAnimChannel();
    CAnimChannel() {};
    /** Copy constructor disabled */
    CAnimChannel(const CAnimChannel&) = delete;
    /** Assignment operator disabled */
    void operator=(const CAnimChannel&) = delete;

    /** Get the channel name
     * \returns channel name */
    std::wstring GetName() const { return mName; }

    /** Set the channel name
     * \param name of channel */
    void SetName(const std::wstring& name ) { mName = name; }

    /** Get a pointer to the Timeline object
     * \returns Pointer to the Timeline object
     */
    CTimeline* GetTimeline() { return mTimeline; }

    /** Set a pointer to the Timeline object
     * \param timeline pointer to the Timeline object
     */
    void SetTimeline(CTimeline* timeline) { mTimeline = timeline; }

    bool IsValid();

    void SetFrame(int currFrame);

    

    /** Class that represents a keyframe */
    class Keyframe
    {
    public:


        /** Default constructor disabled */
        Keyframe() = delete;
        /** Copy constructor disabled */
        Keyframe(const Keyframe&) = delete;
        /** Assignment operator disabled */
        void operator=(const Keyframe&) = delete;

        /** Get the frame
        * \returns frame */
        double GetFrame() const { return mFrame; }

        /** Set the frame
        * \param frame */
        void SetFrame(int frame) { mFrame = frame; }

        /** Use this keyframe as keyframe 1 */
        virtual void UseAs1() = 0;
        
        /** Use this keyframe as keyframe 2 */
        virtual void UseAs2() = 0;

        /** Use this keyframe as the angle */
        virtual void UseOnly() = 0;

    protected:
        /** Constructor
         * \param channel Channel we are associated with */
        Keyframe(CAnimChannel* channel) : mChannel(channel) {}
    private:
        int mFrame; ///< the frame the keyframe is on

        /// The channel this keyframe is associated with
        CAnimChannel* mChannel;
    };

    void InsertKeyframe(std::shared_ptr<Keyframe> keyframe);

    /**
     * Compute an interpolation between two keyframes
     *
     * \param t A t value. t=0 means keyframe1, t=1 means keyframe2. Other values
     * interpolate between.
     */
    virtual void Tween(double t) {};

    void DeleteKeyframe();

private:
    std::wstring mName; ///< name of the channel
    int mKeyframe1 = -1; ///< keyframe behind
    int mKeyframe2 = -1; ///< keyframe infront

    /// The timeline object
    CTimeline* mTimeline = nullptr;

    /// The collection of keyframes for this channel
    std::vector<std::shared_ptr<Keyframe>> mKeyframes;
};

