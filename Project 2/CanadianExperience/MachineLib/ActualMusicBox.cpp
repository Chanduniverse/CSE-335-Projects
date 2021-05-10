/**
 * \file ActualMusicBox.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "ActualMusicBox.h"
#include "Component.h"
#include "MusicBox.h"

CActualMusicBox::CActualMusicBox()
{
}

void CActualMusicBox::AddComponent(std::shared_ptr<CComponent> component)
{
	mComponents.push_back(component);
	component->SetMusicBox(this);

}

void CActualMusicBox::Draw(Gdiplus::Graphics* graphics)
{
	for (auto component : mComponents)
	{
		component->SetTime((mMusicBox->GetFrame() / 30.0));
		component->Draw(graphics, mMusicBox->GetX(), mMusicBox->GetY());
	}

}