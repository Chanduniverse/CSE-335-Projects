/**
 * \file Clamp.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#include "BezierEndPoint.h"

#pragma once

/**
 * Class that represents a clamp
 */
class CClamp :
    public CBezierEndPoint
{
public:
    /** The Constructor
     * \param x
     * \param y
     * \param rot
     * \param speed */
    CClamp(int x, int y, double rot, double speed);
};

