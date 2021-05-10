/**
 * \file PictureFactory.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "UnmaskedSpartyFactory.h"
#include "ImageDrawable.h"

using namespace std;
using namespace Gdiplus;

/** Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI =
        make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    CHaroldFactory hfactory;
    auto harold = hfactory.Create();

    // Create and add Harold
    CUnmaskedSpartyFactory ufactory;
    auto unmasked = ufactory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(400, 500));

    unmasked->SetPosition(Point(700, 500));

    picture->AddActor(harold);
    picture->AddActor(unmasked);

    return picture;
}