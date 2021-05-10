/**
 * \file DecorCastle.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include <string>
#include <memory>
#include "DecorCastle.h"

using namespace Gdiplus;
using namespace std;
/// Fish filename 
const wstring CastleImageName = L"images/castle.png";

/**
* Constructor
* \param aquarium Aquarium this fish is a member of
*/
CDecorCastle::CDecorCastle(CAquarium* aquarium) :
    CItem(aquarium, CastleImageName)
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return sharedptr xmlnode
 */
std::shared_ptr<xmlnode::CXmlNode>
CDecorCastle::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CItem::XmlSave(node);
    itemNode->SetAttribute(L"type", L"castle");

    return itemNode;
}
