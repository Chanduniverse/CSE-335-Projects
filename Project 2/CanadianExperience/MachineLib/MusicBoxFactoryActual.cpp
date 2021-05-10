/**
 * \file MusicBoxFactoryActual.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "MusicBoxFactoryActual.h"

#include "ActualMusicBox.h"
#include "Component.h"
#include "CardReader.h"
#include "Shape.h"
#include "Cylinder.h"
#include "Chime.h"
#include "Cymbal.h"
#include "Drum.h"
#include "Tubing.h"
using namespace std;
using namespace Gdiplus;

// Locations of stuff
const int BaseWidth = 650; ///< width
const int BaseHeight = 10; ///< height

// All of the centers (X)
const int FrameworkCenter = 25; ///< center
const int CardReaderCenter = -250; ///< reader center
const int CylinderCenter = 63; ///< cylinder center
const int ChimesCenter = 47; ///< chimes center
const int CymbalAndDrumCenter = 275; ///< cymbal drum center
const int ClampingPostCenter = -150; ///< post center

const int CylinderBottom = -95; ///< cylinder bottom
const int ChimeTop = -335; ///< chime top
const int CylinderAndChimesSpacing = 55; ///< spacing
const int NumChimes = 5; ///< chimes

/**
 * Create a machine object
 * \returns Object of type CMachine
 */
std::shared_ptr<CActualMusicBox> CMusicBoxFactoryActual::CreateMachine(int machineNumber)
{
    if (machineNumber == 1)
    {
        

        auto box = make_shared<CActualMusicBox>();
        // The base, just a flat to sit things on
        auto base = make_shared<CShape>();
        base->Rectangle(-BaseWidth / 2, BaseHeight, BaseWidth, BaseHeight);
        base->SetColor(Color::DarkGray);
        box->AddComponent(base);

        auto framework = make_shared<CShape>();
        framework->SetImage(L"images/framework.png");
        framework->Rectangle(-framework->GetImageWidth() / 2, 0);
        framework->SetPosition(FrameworkCenter, 0);
        box->AddComponent(framework);



        auto reader = make_shared<CCardReader>();
        reader->LoadCard(L"images/suzanna.png");
        reader->SetPosition(CardReaderCenter, 0);
        box->AddComponent(reader);

        // Vector to collect the cylinders so we can 
    // run tubing to them later.
        std::vector<std::shared_ptr<CCylinder>> cylinders;
        int ChimeLength[] = { 220, 170, 125, 100, 75 };

        wchar_t* sounds[] = { L"audio/chimeC3.wav",
        L"audio/chimeD3.wav",
        L"audio/chimeE3.wav",
        L"audio/chimeG3.wav",
        L"audio/chimeA3.wav" };

        //
        // The cylinders and chimes
        //
        int cylinderX = -CylinderAndChimesSpacing * NumChimes / 2 + CylinderCenter;
        int chimeX = -CylinderAndChimesSpacing * NumChimes / 2 + ChimesCenter;
        for (int i = 0; i < NumChimes; i++) {


            //
            // The chime
            //
            auto chime = make_shared<CChime>(ChimeLength[i]);
            chime->SetPosition(chimeX, ChimeTop);
            box->AddComponent(chime);

            //
            // The cylinder that hits the chime
            //
            auto cylinder = make_shared<CCylinder>();
            cylinder->SetPosition(cylinderX, CylinderBottom);
            box->AddComponent(cylinder);
            cylinders.push_back(cylinder);

            // Connect the motion
            cylinder->SetMotionSink(chime);

            // Add sound to the chime
            auto channel = box->GetWavPlayer()->CreateChannel(sounds[i]);
            chime->SetAudioChannel(channel);

            // Move to the next x locations
            cylinderX += CylinderAndChimesSpacing;
            chimeX += CylinderAndChimesSpacing;
        }

        //
        // The cymbal
        //
        auto cymbal = make_shared<CCymbal>();
        cymbal->SetPosition(CymbalAndDrumCenter, 0);
        box->AddComponent(cymbal);

        auto channel = box->GetWavPlayer()->CreateChannel(L"audio/cymbal.wav");
        cymbal->SetAudioChannel(channel);

        // Cantilever to hold the cylinder
        auto cant = make_shared<CShape>();
        cant->SetImage(L"images/cantilever.png");
        cant->Rectangle(0, 0);   // 0,0 is lower right corner
        cant->SetPosition(framework->GetImageWidth() / 2 - 46, -framework->GetImageHeight() + 3);
        box->AddComponent(cant);

        auto cymbalCylinder = make_shared<CCylinder>();
        cymbalCylinder->SetPosition(cant->GetX() + 100, cant->GetY() - 2);
        cymbalCylinder->SetRotation(0.5);
        cymbalCylinder->SetMaxExtent(0.55);
        box->AddComponent(cymbalCylinder);

        cymbalCylinder->SetMotionSink(cymbal);

        //
        // The drum
        //
        auto drum = make_shared<CDrum>();
        drum->SetPosition(CymbalAndDrumCenter, 0);
        box->AddComponent(drum);

        // Block to hold the cylinder
        auto block = make_shared<CShape>();
        block->SetImage(L"images/angle-block.png");
        block->Rectangle(-block->GetImageWidth(), 0);   // 0,0 is lower right corner
        block->SetPosition(91, 0);
        box->AddComponent(block);

        auto drumCylinder = make_shared<CCylinder>();
        drumCylinder->SetPosition(90, -30);
        drumCylinder->SetRotation(0.25);
        box->AddComponent(drumCylinder);

        drumCylinder->SetMotionSink(drum);

        channel = box->GetWavPlayer()->CreateChannel(L"audio/kick.wav");
        drum->SetAudioChannel(channel);


        reader->GetSource(8)->SetSink(cymbalCylinder->GetSink());
        reader->GetSource(9)->SetSink(drumCylinder->GetSink());

        //
        // Clamping post for the tubing
        //
        auto post = make_shared<CShape>();
        post->SetImage(L"images/clamping-post.png");
        post->Rectangle(-post->GetImageWidth() / 2, 0);
        post->SetPosition(ClampingPostCenter, 0);
        box->AddComponent(post);

        //
        // We do the tubing last so it is on top
        //
        for (int i = 0; i < 5; i++)
        {
            auto tubing = make_shared<CTubing>();
            reader->GetSource(i)->SetSpeed(50);
            reader->GetSource(i)->SetSink(tubing->GetSink());
            tubing->GetSource()->SetSink(cylinders[4 - i]->GetSink());

            tubing->GetSink()->SetPos(reader->GetSource(i)->GetPosX(), reader->GetSource(i)->GetPosY());
            tubing->GetSink()->SetRotation(reader->GetSource(i)->GetRotation());
            tubing->GetSink()->SetSpeed(reader->GetSource(i)->GetSpeed());

            tubing->GetSource()->SetPos(cylinders[4 - i]->GetX(), cylinders[4 - i]->GetY());
            tubing->GetSource()->SetRotation(cylinders[4 - i]->GetSink()->GetRotation());
            tubing->GetSource()->SetSpeed(-20);

            box->AddComponent(tubing);

            tubing->AddClamp(ClampingPostCenter, -10 - 10 * i, 0.75, 50);

            tubing->AddClamp(ClampingPostCenter + 20, -10 - 10 * i, 0.75, 50);

        }

        auto tubing = make_shared<CTubing>();
        reader->GetSource(9)->SetSink(tubing->GetSink());
        reader->GetSource(9)->SetSpeed(25);
        reader->GetSource(9)->SetSpeed(50);
        tubing->GetSource()->SetSink(cymbalCylinder->GetSink());
        box->AddComponent(tubing);

        tubing->AddClamp(-162, -90, 0.5, 50);
        tubing->AddClamp(-162, -360, 0.5, 100);

        tubing->GetSink()->SetPos(reader->GetSource(9)->GetPosX(), reader->GetSource(9)->GetPosY());
        tubing->GetSink()->SetRotation(reader->GetSource(9)->GetRotation());
        tubing->GetSink()->SetSpeed(reader->GetSource(9)->GetSpeed());

        tubing->GetSource()->SetPos(cymbalCylinder->GetX(), cymbalCylinder->GetY());
        tubing->GetSource()->SetRotation(cymbalCylinder->GetSink()->GetRotation());
        tubing->GetSource()->SetSpeed(70);

        tubing = make_shared<CTubing>();
        reader->GetSource(8)->SetSpeed(10);
        reader->GetSource(8)->SetSink(tubing->GetSink());
        tubing->GetSource()->SetSink(drumCylinder->GetSink());
        box->AddComponent(tubing);

        tubing->GetSink()->SetPos(reader->GetSource(8)->GetPosX(), reader->GetSource(8)->GetPosY());
        tubing->GetSink()->SetRotation(reader->GetSource(8)->GetRotation());
        tubing->GetSink()->SetSpeed(reader->GetSource(8)->GetSpeed());

        tubing->GetSource()->SetPos(drumCylinder->GetX(), drumCylinder->GetY());
        tubing->GetSource()->SetRotation(drumCylinder->GetSink()->GetRotation());
        tubing->GetSource()->SetSpeed(-20);

        tubing->AddClamp(ClampingPostCenter, -10 - 10 * 5, 0.75, 50);

        // Clamping post clamps for the tubing
        auto clamps = make_shared<CShape>();
        clamps->SetImage(L"images/clamping-post-clamps.png");
        clamps->Rectangle(-clamps->GetImageWidth() / 2, 0);
        clamps->SetPosition(ClampingPostCenter, 0);
        box->AddComponent(clamps);


        return box;
    }
    else if (machineNumber == 2)
    {

        auto box = make_shared<CActualMusicBox>();
        // The base, just a flat to sit things on
        auto base = make_shared<CShape>();
        base->Rectangle(-BaseWidth / 2, BaseHeight, BaseWidth, BaseHeight);
        base->SetColor(Color::DarkGray);
        box->AddComponent(base);

        auto framework = make_shared<CShape>();
        framework->SetImage(L"images/framework.png");
        framework->Rectangle(-framework->GetImageWidth() / 2, 0);
        framework->SetPosition(FrameworkCenter, 0);
        box->AddComponent(framework);



        auto reader = make_shared<CCardReader>();
        reader->LoadCard(L"images/mary.png");
        reader->SetPosition(CardReaderCenter, 0);
        box->AddComponent(reader);

        // Vector to collect the cylinders so we can 
    // run tubing to them later.
        std::vector<std::shared_ptr<CCylinder>> cylinders;
        int ChimeLength[] = { 220, 170, 125, 100, 75 };

        wchar_t* sounds[] = { L"audio/chimeC3.wav",
        L"audio/chimeD3.wav",
        L"audio/chimeE3.wav",
        L"audio/chimeG3.wav",
        L"audio/chimeA3.wav" };

        //
        // The cylinders and chimes
        //
        int cylinderX = -CylinderAndChimesSpacing * NumChimes / 2 + CylinderCenter;
        int chimeX = -CylinderAndChimesSpacing * NumChimes / 2 + ChimesCenter;
        for (int i = 0; i < NumChimes; i++) {


            //
            // The chime
            //
            auto chime = make_shared<CChime>(ChimeLength[i]);
            chime->SetPosition(chimeX, ChimeTop);
            box->AddComponent(chime);

            //
            // The cylinder that hits the chime
            //
            auto cylinder = make_shared<CCylinder>();
            cylinder->SetPosition(cylinderX, CylinderBottom);
            box->AddComponent(cylinder);
            cylinders.push_back(cylinder);

            // Connect the motion
            cylinder->SetMotionSink(chime);

            // Add sound to the chime
            auto channel = box->GetWavPlayer()->CreateChannel(sounds[i]);
            chime->SetAudioChannel(channel);

            // Move to the next x locations
            cylinderX += CylinderAndChimesSpacing;
            chimeX += CylinderAndChimesSpacing;
        }

        //
        // The cymbal
        //
        auto cymbal = make_shared<CCymbal>();
        cymbal->SetPosition(CymbalAndDrumCenter, 0);
        box->AddComponent(cymbal);

        auto channel = box->GetWavPlayer()->CreateChannel(L"audio/cymbal.wav");
        cymbal->SetAudioChannel(channel);

        // Cantilever to hold the cylinder
        auto cant = make_shared<CShape>();
        cant->SetImage(L"images/cantilever.png");
        cant->Rectangle(0, 0);   // 0,0 is lower right corner
        cant->SetPosition(framework->GetImageWidth() / 2 - 46, -framework->GetImageHeight() + 3);
        box->AddComponent(cant);

        auto cymbalCylinder = make_shared<CCylinder>();
        cymbalCylinder->SetPosition(cant->GetX() + 100, cant->GetY() - 2);
        cymbalCylinder->SetRotation(0.5);
        cymbalCylinder->SetMaxExtent(0.55);
        box->AddComponent(cymbalCylinder);

        cymbalCylinder->SetMotionSink(cymbal);

        //
        // The drum
        //
        auto drum = make_shared<CDrum>();
        drum->SetPosition(CymbalAndDrumCenter, 0);
        box->AddComponent(drum);

        // Block to hold the cylinder
        auto block = make_shared<CShape>();
        block->SetImage(L"images/angle-block.png");
        block->Rectangle(-block->GetImageWidth(), 0);   // 0,0 is lower right corner
        block->SetPosition(91, 0);
        box->AddComponent(block);

        auto drumCylinder = make_shared<CCylinder>();
        drumCylinder->SetPosition(90, -30);
        drumCylinder->SetRotation(0.25);
        box->AddComponent(drumCylinder);

        drumCylinder->SetMotionSink(drum);

        channel = box->GetWavPlayer()->CreateChannel(L"audio/kick.wav");
        drum->SetAudioChannel(channel);


        reader->GetSource(8)->SetSink(cymbalCylinder->GetSink());
        reader->GetSource(9)->SetSink(drumCylinder->GetSink());

        //
        // Clamping post for the tubing
        //
        auto post = make_shared<CShape>();
        post->SetImage(L"images/clamping-post.png");
        post->Rectangle(-post->GetImageWidth() / 2, 0);
        post->SetPosition(ClampingPostCenter, 0);
        box->AddComponent(post);

        //
        // We do the tubing last so it is on top
        //
        for (int i = 0; i < 5; i++)
        {
            auto tubing = make_shared<CTubing>();
            reader->GetSource(i)->SetSpeed(50);
            reader->GetSource(i)->SetSink(tubing->GetSink());
            tubing->GetSource()->SetSink(cylinders[4 - i]->GetSink());

            tubing->GetSink()->SetPos(reader->GetSource(i)->GetPosX(), reader->GetSource(i)->GetPosY());
            tubing->GetSink()->SetRotation(reader->GetSource(i)->GetRotation());
            tubing->GetSink()->SetSpeed(reader->GetSource(i)->GetSpeed());

            tubing->GetSource()->SetPos(cylinders[4 - i]->GetX(), cylinders[4 - i]->GetY());
            tubing->GetSource()->SetRotation(cylinders[4 - i]->GetSink()->GetRotation());
            tubing->GetSource()->SetSpeed(-20);

            box->AddComponent(tubing);

            tubing->AddClamp(ClampingPostCenter, -10 - 10 * i, 0.75, 50);

            tubing->AddClamp(ClampingPostCenter + 20, -10 - 10 * i, 0.75, 50);

        }

        auto tubing = make_shared<CTubing>();
        reader->GetSource(9)->SetSink(tubing->GetSink());
        reader->GetSource(9)->SetSpeed(25);
        reader->GetSource(9)->SetSpeed(50);
        tubing->GetSource()->SetSink(cymbalCylinder->GetSink());
        box->AddComponent(tubing);

        tubing->AddClamp(-162, -90, 0.5, 50);
        tubing->AddClamp(-162, -360, 0.5, 100);

        tubing->GetSink()->SetPos(reader->GetSource(9)->GetPosX(), reader->GetSource(9)->GetPosY());
        tubing->GetSink()->SetRotation(reader->GetSource(9)->GetRotation());
        tubing->GetSink()->SetSpeed(reader->GetSource(9)->GetSpeed());

        tubing->GetSource()->SetPos(cymbalCylinder->GetX(), cymbalCylinder->GetY());
        tubing->GetSource()->SetRotation(cymbalCylinder->GetSink()->GetRotation());
        tubing->GetSource()->SetSpeed(70);

        tubing = make_shared<CTubing>();
        reader->GetSource(8)->SetSpeed(10);
        reader->GetSource(8)->SetSink(tubing->GetSink());
        tubing->GetSource()->SetSink(drumCylinder->GetSink());
        box->AddComponent(tubing);

        tubing->GetSink()->SetPos(reader->GetSource(8)->GetPosX(), reader->GetSource(8)->GetPosY());
        tubing->GetSink()->SetRotation(reader->GetSource(8)->GetRotation());
        tubing->GetSink()->SetSpeed(reader->GetSource(8)->GetSpeed());

        tubing->GetSource()->SetPos(drumCylinder->GetX(), drumCylinder->GetY());
        tubing->GetSource()->SetRotation(drumCylinder->GetSink()->GetRotation());
        tubing->GetSource()->SetSpeed(-20);

        tubing->AddClamp(ClampingPostCenter, -10 - 10 * 5, 0.75, 50);

        // Clamping post clamps for the tubing
        auto clamps = make_shared<CShape>();
        clamps->SetImage(L"images/clamping-post-clamps.png");
        clamps->Rectangle(-clamps->GetImageWidth() / 2, 0);
        clamps->SetPosition(ClampingPostCenter, 0);
        box->AddComponent(clamps);


        return box;
    }
    else
    {
        return make_shared<CActualMusicBox>();
    }
    
}