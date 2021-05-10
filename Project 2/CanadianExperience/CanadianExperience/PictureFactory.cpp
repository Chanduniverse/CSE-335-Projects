/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "MachineDrawable.h"
using namespace std;
using namespace Gdiplus;

/**
 * Constructor
*/
CPictureFactory::CPictureFactory()
{
}

/**
 * Destructor
*/
CPictureFactory::~CPictureFactory()
{
}


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
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Machine
    /**/
    shared_ptr<CActor> machine_f = make_shared<CActor>(L"Machine");
    auto machine = make_shared<CMachineDrawable>(L"Machine");
    machine->SetMachineNumber(2);
    machine_f->SetRoot(machine);
    machine_f->AddDrawable(machine);

    machine_f->SetPosition(Point(200, 200));
    picture->AddActor(machine_f);
    picture->SetMachine(machine);

    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(750, 500));

    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(520, 500));
    picture->AddActor(sparty);

    

    return picture;
}
