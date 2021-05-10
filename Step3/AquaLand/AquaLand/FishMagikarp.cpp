/**
 * \file FishBeta.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "FishMagikarp.h"
#include <string>
#include <memory>


using namespace Gdiplus;
using namespace std;
/// Fish filename 
const wstring FishMagikarpImageName = L"images/magikarp.png";
const wstring FishGyaradosImageName = L"images/gyarados.png";
const wstring FishRedGyaradosImageName = L"images/red_gyarados.png";

/**
* Constructor
* \param aquarium Aquarium this fish is a member of
*/
CFishMagikarp::CFishMagikarp(CAquarium* aquarium) :
    CFish(aquarium, FishMagikarpImageName)
{
    if (rand() / (RAND_MAX + 1.0) < 0.2)
    {
        mGyaradosImage = unique_ptr<Bitmap>(Bitmap::FromFile(FishRedGyaradosImageName.c_str()));
    }
    else {
        mGyaradosImage = unique_ptr<Bitmap>(Bitmap::FromFile(FishGyaradosImageName.c_str()));
    }
    
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return sharedptr xmlnode
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishMagikarp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);
    itemNode->SetAttribute(L"type", L"magikarp");

    return itemNode;
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFishMagikarp::Update(double elapsed)
{
    CFish::Update(elapsed);
    if (GetTime() >= 5)
    {
        evolved = TRUE;
    }

}

/**
 * Draw our item
 * \param graphics The graphics context to draw on
 */
void CFishMagikarp::Draw(Gdiplus::Graphics* graphics)
{
    if (evolved)
    {
        double wid = mGyaradosImage->GetWidth();
        double hit = mGyaradosImage->GetHeight();

        if (GetMirror())
        {
            graphics->DrawImage(mGyaradosImage.get(),
                float(GetX() + wid / 2), float(GetY() - hit / 2),
                -(float)mGyaradosImage->GetWidth(), (float)mGyaradosImage->GetHeight());
        }
        else
        {
            graphics->DrawImage(mGyaradosImage.get(),
                float(GetX() - wid / 2), float(GetY() - hit / 2),
                (float)mGyaradosImage->GetWidth(), (float)mGyaradosImage->GetHeight());
        }
    }
    else
    {
        double wid = mItemImage->GetWidth();
        double hit = mItemImage->GetHeight();

        if (GetMirror())
        {
            graphics->DrawImage(mItemImage.get(),
                float(GetX() + wid / 2), float(GetY() - hit / 2),
                -(float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
        }
        else
        {
            graphics->DrawImage(mItemImage.get(),
                float(GetX() - wid / 2), float(GetY() - hit / 2),
                (float)mItemImage->GetWidth(), (float)mItemImage->GetHeight());
        }
    }
    
}