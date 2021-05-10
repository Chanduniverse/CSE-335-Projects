/**
 * \file Tubing.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once
#include "Component.h"
#include <memory>
#include "AirReceiver.h"
#include "AirPump.h"
#include "Clamp.h"

/**
 * Class that handles tubing.
 */
class CTubing :
    public CComponent
{
public:
    CTubing();

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
    std::shared_ptr<CAirReceiver> GetSink() { return mAirReceiver; }

    /** Get Source
     * \return source */
    std::shared_ptr<CAirPump> GetSource() { return mAirPump; }

    /** Set Sink
     * \param rec */
    void SetSink(std::shared_ptr<CAirReceiver> rec) { mAirReceiver = rec;}

    /** Set Source
     * \param pump */
    void SetSource(std::shared_ptr<CAirPump> pump) { mAirPump = pump;}

    /** Add clamp
     * \param x
     * \param y
     * \param rot
     * \param speed
     */
    void AddClamp(int x, int y, double rot, double speed);

private:
    std::shared_ptr<CAirPump> mAirPump; ///< pump
    std::shared_ptr<CAirReceiver> mAirReceiver; ///< receiver
    std::vector<std::shared_ptr<CClamp>> mClamps; ///< tubing clamps

};

