/**
 * \file FishBashful.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "FishBashful.h"
#include <string>
#include <memory>


using namespace Gdiplus;
using namespace std;
/// Fish filename
const wstring FishBashfulImageName = L"images/bashful-green.png";

/// Blushing Fish filename
const wstring FishBlushBashfulImageName = L"images/bashful-red.png";

/// Maximum speed in the X direction in
    /// in pixels per second
const double MaxSpeedX = 10;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 10;

/**
* Constructor
* \param aquarium Aquarium this fish is a member of
*/
CFishBashful::CFishBashful(CAquarium* aquarium) :
    CFish(aquarium, FishBashfulImageName)
{
    ChangeSpeed(((double)rand() / RAND_MAX) * MaxSpeedX, ((double)rand() / RAND_MAX) * MaxSpeedY);
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return sharedptr xmlnode
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishBashful::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);
    itemNode->SetAttribute(L"type", L"bashful");

    return itemNode;
}
