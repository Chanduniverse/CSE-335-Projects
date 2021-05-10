/**
 * \file Instrument.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "Instrument.h"

void CInstrument::OnInstrumentHit()
{
    
    if (!mPreviouslyHit)
    {
        if (mChannel != nullptr)
        {
            mChannel->Play();
            mPreviouslyHit = false;
        }
    }
    mPreviouslyHit = true;
}

void CInstrument::OnMovement(double force)
{
    if (force > 0)
    {

        OnInstrumentHit();

    }
    else
    {
        mPreviouslyHit = false;
    }
}