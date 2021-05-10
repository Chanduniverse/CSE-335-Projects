/**
 * \file Cylinder.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once
#include "Component.h"
#include "Polygon.h"
#include "Instrument.h"

class CAirReceiver;

/**
 * Class that represents a cylinder.
 */
class CCylinder :
    public CComponent
{
public:
    CCylinder();
    /// Copy constructor (disabled)
    CCylinder(const CCylinder&) = delete;

    /// Assignment operator (disabled)
    void operator=(const CCylinder&) = delete;

    /** Draw the drawable
     * \param graphics Graphics object to draw on
     * \param X
     * \param Y */
    virtual void Draw(Gdiplus::Graphics* graphics, int X, int Y) override;

    /** Set Time
     * \param time */
    virtual void SetTime(double time) {};

    /** Get Sink
     * \return sink */
    std::shared_ptr<CAirReceiver> GetSink() { return mReceiver; }

    /** Air pumped
     * \param input the air being pumped in */
    void OnAirPumped(double input);

    /** Set Motion Sink
     * \param sink */
    void SetMotionSink(std::shared_ptr<CInstrument> sink) { mMotionSink = sink; }

    /** Set Rotation
     * \param rot */
    void SetRotation(double rot) { mRotation = rot; }

    /** Set max extent
     * \param max extent */
    void SetMaxExtent(double max) { mMaxExtent = max; }

private:
    CPolygon mBase; ///< base image
    CPolygon mCylinder; ///< cylinder
    CPolygon mRam; ///< ram image

    double mRotation = 0; ///< rotation
    double mMaxExtent = 1; ///< max extent
    std::shared_ptr<CAirReceiver> mReceiver = nullptr; ///< receiver
    std::shared_ptr<CInstrument> mMotionSink = nullptr; ///< motion sink

    int mRamPosition = 0; ///< ram position
};