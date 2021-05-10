/**
 * \file UnmaskedSpartyFactory.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "UnmaskedSpartyFactory.h"
#include "PolyDrawable.h"
#include "ImageDrawable.h"
#include "HeadTop.h"

using namespace std;
using namespace Gdiplus;

/** This is a concrete factory method that creates our Unmasked Sparty actor.
* \returns Pointer to an actor object.
*/
std::shared_ptr<CActor> CUnmaskedSpartyFactory::Create()
{
    shared_ptr<CActor> actor = make_shared<CActor>(L"Unmasked Sparty");

    auto shirt = make_shared<CImageDrawable>(L"Shirt", L"images/sparty_torso.png");
    shirt->SetCenter(Point(74, 148));
    shirt->SetPosition(Point(0, -114));
    actor->SetRoot(shirt);

    auto lleg = make_shared<CImageDrawable>(L"Left Leg", L"images/sparty_lleg.png");
    lleg->SetCenter(Point(11, 9));
    lleg->SetPosition(Point(7, 10));
    shirt->AddChild(lleg);

    auto rleg = make_shared<CImageDrawable>(L"Right Leg", L"images/sparty_rleg.png");
    rleg->SetCenter(Point(39, 9));
    rleg->SetPosition(Point(-27, 10));
    shirt->AddChild(rleg);

    auto headb = make_shared<CImageDrawable>(L"Head Bottom", L"images/headb2.png");
    headb->SetCenter(Point(44, 31));
    headb->SetPosition(Point(0, -130));
    shirt->AddChild(headb);

    auto headt = make_shared<CHeadTop>(L"Head Top", L"images/headt2.png");
    headt->SetCenter(Point(55, 109));
    headt->SetPosition(Point(0, -31));
    headt->SetRightEyebrow(Point(31, 63), Point(48, 60));
    headt->SetLeftEyebrow(Point(63, 60), Point(79, 62));
    headt->SetEyes(Point(42, 80), Point(69, 79));
    headb->AddChild(headt);

    auto larm = make_shared<CImageDrawable>(L"Left Arm", L"images/sparty_larm.png");
    larm->SetCenter(Point(20, 9));
    larm->SetPosition(Point(50, -130));
    shirt->AddChild(larm);


    auto rarm = make_shared<CImageDrawable>(L"Right Arm", L"images/sparty_rarm.png");
    rarm->SetCenter(Point(100, 9));
    rarm->SetPosition(Point(-50, -130));
    shirt->AddChild(rarm);



    actor->AddDrawable(larm);
    actor->AddDrawable(rarm);
    actor->AddDrawable(rleg);
    actor->AddDrawable(lleg);
    actor->AddDrawable(shirt);
    actor->AddDrawable(headb);
    actor->AddDrawable(headt);

    return actor;
}