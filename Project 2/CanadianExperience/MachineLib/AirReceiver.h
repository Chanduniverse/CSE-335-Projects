/**
 * \file AirReceiver.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once
#include "AirSink.h"
#include "Cylinder.h"
#include "BezierEndPoint.h"

class CAirPump;

/**
 * Class that represents an air receiver.
 */
class CAirReceiver :
    public CAirSink, public CBezierEndPoint
{
public:
    /** Contructor */
    CAirReceiver() {}

    /// Copy constructor (disabled)
    CAirReceiver(const CAirReceiver&) = delete;

    /// Assignment operator (disabled)
    void operator=(const CAirReceiver&) = delete;

    /** Air pumped
     * \param input the air being pumped in */
    virtual void OnAirPumped(double input) override;

    /** Set Component
     * \param comp */
    void SetComponent(CCylinder* comp) { mMainComponent = comp; }

    /** Set Pump
     * \param pump */
    void SetPump(std::shared_ptr<CAirPump> pump) { mAirPump = pump; }

private:
    double mInput = 0; ///< input
    double mMaxInput = 0; ///< max input
    CCylinder* mMainComponent = nullptr; ///< main component
    std::shared_ptr<CAirPump> mAirPump; ///< air pump

};

