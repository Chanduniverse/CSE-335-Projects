/**
 * \file ChooseRocketPadVisitor.h
 *
 * \author Chandan Aralikatti
 *
 * Class that implements empty pad finder
 */


#pragma once
#include "TileVisitor.h"
#include "TileRocketPad.h"
#include "Rocket.h"


/**
 * Class that finds pads without rocket
 */
class CChooseRocketPadVisitor : public CTileVisitor
{
public:
	virtual void VisitRocketPad(CTileRocketPad* pad);

	/** Find an empty pad
	 * \returns empty pad */
	CTileRocketPad* FindPad() { return mChosenPad; }


private:
	/// the chosen empty pad
	CTileRocketPad* mChosenPad = nullptr;

};