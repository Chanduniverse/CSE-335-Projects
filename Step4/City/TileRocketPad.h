/**
 * \file TileRocketPad.h
 *
 * \author 
 *
 * Class that implements a rocket pad.
 */

#pragma once

#include "Tile.h"

class CRocket;

/**
 * Class that implements a rocket pad.
 * 
 * This is where rockets take off and land.
*/
class CTileRocketPad : public CTile
{
public:
    CTileRocketPad(CCity* city);

    ///  Default constructor (disabled)
    CTileRocketPad() = delete;

    ///  Copy constructor (disabled)
    CTileRocketPad(const CTileRocketPad&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    virtual void Report(std::shared_ptr<CMemberReport> report) override;

    virtual bool PendingDelete() override;

    void RocketIsGone();
    
    void RocketHasLanded();

    void Update(double elapsed);

    void Draw(Gdiplus::Graphics* graphics);

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CTileVisitor* visitor) override { visitor->VisitRocketPad(this); }

    /** Check if pad has rocket
     * \return True if pad has rocket */
    bool HasRocket() { return mHasRocket; }

    /** Associate rocket with pad
     * \param rocket The rocket to be associated with */
    void GiveRocket(std::shared_ptr<CRocket> rocket) { mHasRocket = true; mRocket = rocket; }

    /** Get rocket
     * \return rocket pointer */
    std::shared_ptr<CRocket> GetRocket() { return mRocket; }

private:

    /// true if pad has rocket
    bool mHasRocket = false;

    /// points to rocket object
    std::shared_ptr<CRocket> mRocket = nullptr;

};

