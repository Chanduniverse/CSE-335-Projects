/**
 * \file Instrument.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once
#include "Component.h"
#include "MotionSink.h"
#include "WavChannel.h"
#include <memory>

/**
 * Class that represents an instrument
 */
class CInstrument :
    public CComponent, public CMotionSink
{
public:
    /** Draw the drawable
     * \param graphics Graphics object to draw on
     * \param X
     * \param Y */
    virtual void Draw(Gdiplus::Graphics* graphics, int X, int Y) override {};
    
    /** Set Audio Channel
     * \param channel audio channel */
    void SetAudioChannel(std::shared_ptr<CWavChannel> channel) { mChannel = channel; }

    /** Instrument Hit
     * \return true if hit */
    bool IsInstrumentHit() { return mPreviouslyHit; }

    /** On Movement
     * \param force */
    virtual void OnMovement(double force) override;

private:
    /** On Instrument Hit
     *  When instrument is hit by cylinder*/
    void OnInstrumentHit();

private:
    bool mPreviouslyHit = false; ///< true if hit before cooldown is over
    std::shared_ptr<CWavChannel> mChannel = nullptr; ///< the sound file
};

