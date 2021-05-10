/**
 * \file Drum.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once
#include "Instrument.h"
#include "Polygon.h"

/**
 * Class that represents a drum
 */
class CDrum :
    public CInstrument
{
public:
    CDrum();

    /// Copy constructor (disabled)
    CDrum(const CDrum&) = delete;

    /// Assignment operator (disabled)
    void operator=(const CDrum&) = delete;

    /** Draw the drawable
     * \param graphics Graphics object to draw on
     * \param X
     * \param Y */
    virtual void Draw(Gdiplus::Graphics* graphics, int X, int Y) override;


private:
    CPolygon mDrum; ///< drum image
};

