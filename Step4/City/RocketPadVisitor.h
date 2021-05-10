/**
 * \file RocketPadVisitor.h
 *
 * \author Chandan Aralikatti
 *
 * Class that handles launching and counting
 */



#pragma once
#include "TileVisitor.h"
#include "TileRocketPad.h"
#include "RocketPadTileVisitor.h"
#include "Rocket.h"

 /**
  * Class that visits multiple rocket pads and handles launching
  */
class CRocketPadVisitor : public CTileVisitor
{
public:
    /** Get the number of Rocket pads
     * \returns Number of Rocket pads */
    int GetNumPads() const { return mNumPads; }

    virtual void VisitRocketPad(CTileRocketPad* pad);

    /** launches rocket
     * \param pad the pad the rocket is launched from
     */
    void LaunchRocket(CRocketPadTileVisitor pad) { pad.GetLandingPad()->GiveRocket(mRocket); mRocket->SetLandingPad(pad.GetLandingPad()); }

    /** Gets launchpad
     * \return pointer to launch pad
     */
    CTileRocketPad* GetLaunchPad() { return mLaunchPad; }

    /** Checks if rocket is in flight or not
     * \return True if rocket in flight
     */
    bool InFlight() { return mRocket->InFlight(); }



private:
    /// Pads counter
    int mNumPads = 0;

    /// Pointer to landing rocket pad tile
    std::shared_ptr<CTile> mLandingTile;

    /// Pointer to launch pad
    CTileRocketPad* mLaunchPad = nullptr;

    /// Pointer to rocket
    std::shared_ptr<CRocket> mRocket = nullptr;

};

