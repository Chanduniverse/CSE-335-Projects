/**
 * \file Fish.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "Fish.h"
#include "Item.h"
#include "Aquarium.h"

 /// Maximum speed in the X direction in
 /// in pixels per second
const double MaxSpeedX = 50;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 50;

CFish::CFish(CAquarium* aquarium, const std::wstring& filename) :
    CItem(aquarium, filename)
{
    mSpeedX = ((double)rand() / RAND_MAX) * MaxSpeedX;
    mSpeedY = ((double)rand() / RAND_MAX) * MaxSpeedY;
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFish::Update(double elapsed)
{
    mTime += elapsed;

    SetLocation(GetX() + mSpeedX * elapsed,
        GetY() + mSpeedY * elapsed);

    if ((mSpeedX > 0 && GetX() >= GetAquarium()->GetWidth() - 10 - GetWidth()/2) || (mSpeedX < 0 && GetX() <= 0 + 10 + GetWidth()/2))
    {
        mSpeedX = -mSpeedX;
        SetMirror(mSpeedX < 0);
    }
    if ((mSpeedY > 0 && GetY() >= GetAquarium()->GetHeight() - 10 - GetHeight() / 2) || (mSpeedY < 0 && GetY() <= 0 + 10 + GetHeight() / 2))
    {
        mSpeedY = -mSpeedY;
    }
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return sharedptr xmlnode
 */
std::shared_ptr<xmlnode::CXmlNode>
CFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CItem::XmlSave(node);
    itemNode->SetAttribute(L"speedx", mSpeedX);
    itemNode->SetAttribute(L"speedy", mSpeedY);

    return itemNode;
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * \param node The Xml node we are loading the item from
 */
void CFish::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CItem::XmlLoad(node);
    mSpeedX = node->GetAttributeDoubleValue(L"speedx", 0);
    mSpeedY = node->GetAttributeDoubleValue(L"speedy", 0);
}


/**
 * changes the speed of the fish
 * \param x the x speed of the fish
 * \param y the y speed of the fish
 */
void CFish::ChangeSpeed(double x, double y)
{
    mSpeedX = x;
    mSpeedY = y;
}