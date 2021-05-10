/**
 * \file TileRocketPad.cpp
 *
 * \author 
 */

#include "pch.h"
#include <sstream>
#include <iostream>
#include "City.h"
#include "TileRocketPad.h"
#include "MemberReport.h"
#include "Rocket.h"
#include "RocketPadVisitor.h"
#include "ChooseRocketPadVisitor.h"

using namespace std;
using namespace Gdiplus;

/// The image to display for the rocket pad
const wstring RocketPadImage = L"pad.png";


/** Constructor
* \param city The city this is a member of
*/
CTileRocketPad::CTileRocketPad(CCity* city) : CTile(city)
{
    SetImage(RocketPadImage);
    CRocketPadVisitor visitor;
    city->Accept(&visitor);
    
    int cnt = visitor.GetNumPads();
    if (cnt == 0)
    {
        
        mRocket = make_shared<CRocket>(city);
        mRocket->SetLaunchingPad(this);
        mHasRocket = true;
    }
    
}


/**  Save this item to an XML node
* \param node The node we are going to be a child of
* \returns Allocated node
*/
std::shared_ptr<xmlnode::CXmlNode> CTileRocketPad::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CTile::XmlSave(node);

    itemNode->SetAttribute(L"type", L"rocketpad");

    return itemNode;
}


/**
 * Generate a report for this  tile.
 * @param report
*/
void CTileRocketPad::Report(std::shared_ptr<CMemberReport> report)
{
    wstringstream str;
    str << L"Rocket Pad";

    report->SetReport(str.str());
}

/**
 * Indicate that this object is about to be deleted by
 * begin dragged into the trash can. If the function
 * override returns false, the delete will not occur.
 * @return true if okay to delete.
*/
bool CTileRocketPad::PendingDelete()
{
    if (mHasRocket)
    {
        CChooseRocketPadVisitor BackupPad;
        
        GetCity()->Accept(&BackupPad);
        auto newPad = BackupPad.FindPad();
        if (mRocket->InFlight())
        {
            if (newPad == nullptr && mRocket->GetLaunchPad() == this && mRocket->GetLandingPad() == this)
            {
                return false;
            }
            if (newPad == nullptr)
            {
                newPad = mRocket->GetLaunchPad();
            }
            if (this == mRocket->GetLaunchPad() && mRocket->GetLandingPad() != this)
            {
                newPad = mRocket->GetLandingPad();
            }
            else
            {
                mRocket->GetLaunchPad()->RocketIsGone();
            }
        }
        if (newPad == nullptr)
        {
            return false;
        }
        newPad->GiveRocket(mRocket); 
        mRocket->SetLaunchingPad(newPad);
    }
    return true;
}

/**
 * This function is called when the rocket has
 * landed on some other pad. It is no longer accessible to
 * this pad.
*/
void CTileRocketPad::RocketIsGone()
{
    mHasRocket = false;
    mRocket = nullptr;
}

/**
 * This function is called when the rocket has landed on this
 * pad. This pad should now become the launching pad.
*/
void CTileRocketPad::RocketHasLanded()
{
    mRocket->SetLaunchingPad(this);
}

/**
 * Update the pad in time.
 *
 * @param elapsed Elasped time in seconds.
*/
void CTileRocketPad::Update(double elapsed)
{
    if (mHasRocket)
    {
        mRocket->Update(this, elapsed);
    }
}

/**
 * Draw the pad.
 * \param graphics The graphics context to draw on.
 */
void CTileRocketPad::Draw(Gdiplus::Graphics* graphics)
{
    CTile::Draw(graphics);
    if (mHasRocket)
    {
        mRocket->Draw(this, graphics);
    }
}