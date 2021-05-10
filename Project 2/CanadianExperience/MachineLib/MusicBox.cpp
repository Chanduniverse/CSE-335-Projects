/**
 * \file MusicBox.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "MusicBox.h"
#include "ActualMusicBox.h"
#include "MusicBoxFactoryActual.h"

CMusicBox::CMusicBox()
{
    SetMachineNumber(1);
}

void CMusicBox::SetMachineNumber(int machine)
{
    CMusicBoxFactoryActual factory;
    mActualMusicBox = factory.CreateMachine(machine);
    mActualMusicBox->SetMusicBox(this);
    mMachine = machine;
}

/**
    * Set the position for the root of the machine
    * \param x X location (pixels)
    * \param y Y location (pixels)
    */
void CMusicBox::SetLocation(int x, int y) { mX = x; mY = y; }


/**
* Set the current machine animation frame
* \param frame Frame number
*/
void CMusicBox::SetMachineFrame(int frame) 
{
    mFrame = frame;
}

/**
* Get the current machine number
* \return Machine number
*/
int CMusicBox::GetMachineNumber() { return mMachine; }

void CMusicBox::DrawMachine(Gdiplus::Graphics* graphics)
{
    mActualMusicBox->Draw(graphics);
}