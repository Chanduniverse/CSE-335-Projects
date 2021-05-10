#include "pch.h"
#include "MachineDrawable.h"
#include "MachineFactory.h"
#include "Timeline.h"
#include "MachineDlg.h"
using namespace std;


CMachineDrawable::CMachineDrawable(const std::wstring& name) :
	CDrawable(name)
{
	CMachineFactory factory;
	mMachine = factory.CreateMachine();
}

/**
 * Set the machine number
 * \param machine Machine number
 */
void CMachineDrawable::SetMachineNumber(int machine)
{
	mMachine->SetMachineNumber(machine);
}

void CMachineDrawable::Draw(Gdiplus::Graphics* graphics)
{
    float scale = 0.5f;
    mMachine->SetMachineFrame(mTimeline->GetCurrentFrame());
    auto save = graphics->Save();
    graphics->TranslateTransform((float)mPlacedPosition.X,
        (float)mPlacedPosition.Y);
    graphics->ScaleTransform(scale, scale);
    mMachine->DrawMachine(graphics);
    
    graphics->Restore(save);
}

void CMachineDrawable::SetTimeline(CTimeline* timeline)
{
    CDrawable::SetTimeline(timeline);
    mTimeline = timeline;
}

INT_PTR CMachineDrawable::GetDialog()
{
    auto dlg = CMachineDlg(mMachine);
    return dlg.DoModal();

}