/**
 * \file RocketPadTileVisitor.h
 *
 * \author Chandan Aralikatti
 *
 * Class that implements single tile visitor
 */

#pragma once
#include "TileVisitor.h"
#include "TileRocketPad.h"

/**
 * Class that visits a single rocket pad
 */
class CRocketPadTileVisitor : public CTileVisitor
{
public:
	virtual void VisitRocketPad(CTileRocketPad* pad);

	/** Determine if tile is rocket pad
	 * \return True if rocketpad */
	bool IsRocketPad() { return mIsRocketPad; }

	/** Get RocketPad of a tile
	 * \return CTileRocketPad* pointer */
	CTileRocketPad* GetLandingPad() { return mLandingPad; }

private:

	/// rocket pad boolean
	bool mIsRocketPad = false;

	/// landing pad pointer
	CTileRocketPad* mLandingPad = nullptr;
};