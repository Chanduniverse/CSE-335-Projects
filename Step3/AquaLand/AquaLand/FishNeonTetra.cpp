/**
 * \file FishNeonTetra.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "FishNeonTetra.h"
#include <string>
#include <memory>


using namespace Gdiplus;
using namespace std;
/// Fish filename 
const wstring FishNeonTetraImageName = L"images/neon-tetra.png";

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 2000;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 2000;

/// Minimum speed in the X direction in
/// in pixels per second
const double MinSpeedX = 1000;

/// Minimum speed in the Y direction in
/// in pixels per second
const double MinSpeedY = 1000;

/**
* Constructor
* \param aquarium Aquarium this fish is a member of
*/
CFishNeonTetra::CFishNeonTetra(CAquarium* aquarium) :
    CFish(aquarium, FishNeonTetraImageName)
{
    ChangeSpeed((MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX)), (MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY)));
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return sharedptr xmlnode
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishNeonTetra::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);
    itemNode->SetAttribute(L"type", L"neontetra");

    return itemNode;
}