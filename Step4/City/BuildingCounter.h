/**
 * \file BuildingCounter.h
 *
 * \author Chandan Aralikatti
 *
 * Class that implements building counter
 */

#pragma once
#include "TileVisitor.h"


/**
 * Class that counts buildings
 */
class CBuildingCounter : public CTileVisitor
{
public:
    /** Get the number of buildings
     * \returns Number of buildings */
    int GetNumBuildings() const { return mNumBuildings; }

    virtual void VisitBuilding(CTileBuilding* building);

private:
    /// Buildings counter
    int mNumBuildings = 0;
};

