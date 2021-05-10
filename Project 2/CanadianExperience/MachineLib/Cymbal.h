/**
 * \file Cymbal.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once
#include "Instrument.h"
#include "Polygon.h"

/**
 * Class that represents a cymbal.
 */

class CCymbal :
    public CInstrument
{
public:
    CCymbal();

    /// Copy constructor (disabled)
    CCymbal(const CCymbal&) = delete;

    /// Assignment operator (disabled)
    void operator=(const CCymbal&) = delete;

    /** Draw the drawable
     * \param graphics Graphics object to draw on
     * \param X
     * \param Y */
    virtual void Draw(Gdiplus::Graphics* graphics, int X, int Y) override;

    /** Set Time
     * \param time */
    virtual void SetTime(double time);

private:
    CPolygon mCymbal; ///< cymbal image
    CPolygon mStand; ///< stand image
    double mVibration = 0; ///< vibration rotation
    double mHitTime = 0; ///< time since last hit
};

