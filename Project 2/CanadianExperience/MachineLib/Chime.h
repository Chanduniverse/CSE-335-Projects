/**
 * \file Chime.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once
#include "Instrument.h"
#include "Polygon.h"

/**
 * Class that represents a chime
 */
class CChime :
    public CInstrument
{
public:
    /** The Constructor
     * \param length */
    CChime(int length);

    /// Copy constructor (disabled)
    CChime(const CChime&) = delete;

    /// Assignment operator (disabled)
    void operator=(const CChime&) = delete;

    /** Draw the drawable
     * \param graphics Graphics object to draw on
     * \param X
     * \param Y */
    virtual void Draw(Gdiplus::Graphics* graphics, int X, int Y) override;


private:
    CPolygon mHammer; ///< hammer image
    CPolygon mTube; ///< tube image
    CPolygon mMount; ///< mount image

};

