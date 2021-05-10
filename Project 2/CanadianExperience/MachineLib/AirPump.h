/**
 * \file AirPump.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once
#include "AirSource.h"
#include "BezierEndPoint.h"
#include <memory>
class CAirReceiver;

/**
 * Class that represents an air pump
 */
class CAirPump :
    public CAirSource, public CBezierEndPoint
{
public:

    CAirPump() {}

    /// Copy constructor (disabled)
    CAirPump(const CAirPump&) = delete;

    /// Assignment operator (disabled)
    void operator=(const CAirPump&) = delete;

    /** Air pumped
     * \param output the air being pumped in */
    virtual void OnAirPumped(double output) override;

    /** Is Valid
     * \return true if mReceiver exists */
    bool IsValid() { if (mReceiver != nullptr) return true; }

    /** Set Sink
     * \param receiver the sink the pump is associated with */
    void SetSink(std::shared_ptr<CAirReceiver> receiver) { mReceiver = receiver; }

private:
    double mOutput = 10; ///< pump output
    std::shared_ptr<CAirReceiver> mReceiver; ///< sink of the pump
};

