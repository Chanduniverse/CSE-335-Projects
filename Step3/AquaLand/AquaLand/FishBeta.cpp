/**
 * \file FishBeta.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "FishBeta.h"
#include <string>
#include <memory>


using namespace Gdiplus;
using namespace std;
 /// Fish filename 
const wstring FishBetaImageName = L"images/beta.png";

/// Maximum speed in the X direction in
    /// in pixels per second
const double MaxSpeedX = 80;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 80;

/// Minimum speed in the X direction in
/// in pixels per second
const double MinSpeedX = 50;

/// Minimum speed in the Y direction in
/// in pixels per second
const double MinSpeedY = 50;

/**
* Constructor
* \param aquarium Aquarium this fish is a member of
*/
CFishBeta::CFishBeta(CAquarium* aquarium) :
    CFish(aquarium, FishBetaImageName)
{
    ChangeSpeed(MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX), MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY));
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return sharedptr xmlnode
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);
    itemNode->SetAttribute(L"type", L"beta");

    return itemNode;
}
