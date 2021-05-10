/**
 * \file Tubing.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "Tubing.h"
using namespace std;
using namespace Gdiplus;

CTubing::CTubing()
{
	mAirPump = make_shared<CAirPump>();
	mAirReceiver = make_shared<CAirReceiver>();
	mAirReceiver->SetPump(mAirPump);
}

void CTubing::Draw(Gdiplus::Graphics* graphics, int X, int Y)
{
	Pen pen(Color::Black, 3);
	auto saveSM = graphics->GetSmoothingMode();
	graphics->SetSmoothingMode(SmoothingMode::SmoothingModeHighQuality);

	auto p2x = (mAirReceiver->GetPosX() + X) - sin(mAirReceiver->GetRotation() * M_PI * 2) * mAirReceiver->GetSpeed();
	auto p2y = (mAirReceiver->GetPosY() + Y) + cos(mAirReceiver->GetRotation() * M_PI * 2) * mAirReceiver->GetSpeed();

	auto p3x = (mAirReceiver->GetPosX() + X) - sin(-mAirReceiver->GetRotation() * M_PI * 2) * mAirReceiver->GetSpeed();
	auto p3y = (mAirReceiver->GetPosY() + Y) + cos(-mAirReceiver->GetRotation() * M_PI * 2) * mAirReceiver->GetSpeed();

	int x = X;
	graphics->DrawBezier(&pen, Point(mAirReceiver->GetPosX() + X, mAirReceiver->GetPosY() + Y), Point(p2x, p2y), Point(p3x, p3y), Point(mClamps[0]->GetPosX() + X, mClamps[0]->GetPosY() + Y));
	auto xx = 99;

	for (int i = 0; i < mClamps.size() - 1; i++)
	{
		p2x = (mClamps[i]->GetPosX() + X) - sin(mClamps[i]->GetRotation() * M_PI * 2) * mClamps[i]->GetSpeed();
		p2y = (mClamps[i]->GetPosY() + Y) + cos(mClamps[i]->GetRotation() * M_PI * 2) * mClamps[i]->GetSpeed();

		p3x = (mClamps[i]->GetPosX() + X) - sin(-mClamps[i]->GetRotation() * M_PI * 2) * mClamps[i]->GetSpeed();
		p3y = (mClamps[i]->GetPosY() + Y) + cos(-mClamps[i]->GetRotation() * M_PI * 2) * mClamps[i]->GetSpeed();
		graphics->DrawBezier(&pen, Point(mClamps[i]->GetPosX() + X, mClamps[i]->GetPosY() + Y), Point(p2x, p2y), Point(p3x, p3y), Point(mClamps[i+1]->GetPosX() + X, mClamps[i+1]->GetPosY() + Y));
	}

	p2x = (mAirPump->GetPosX() + X) - sin(mAirPump->GetRotation() * M_PI * 2) * mAirPump->GetSpeed();
	p2y = (mAirPump->GetPosY() + Y) + cos(mAirPump->GetRotation() * M_PI * 2) * mAirPump->GetSpeed();

	p3x = (mAirPump->GetPosX() + X) - sin(-mAirPump->GetRotation() * M_PI * 2) * mAirPump->GetSpeed();
	p3y = (mAirPump->GetPosY() + Y) + cos(-mAirPump->GetRotation() * M_PI * 2) * mAirPump->GetSpeed();


	graphics->DrawBezier(&pen, Point(mAirPump->GetPosX() + X, mAirPump->GetPosY() + Y), Point(p2x, p2y), Point(p3x, p3y), Point(mClamps[mClamps.size() - 1]->GetPosX() + X, mClamps[mClamps.size() - 1]->GetPosY() + Y));

	graphics->SetSmoothingMode(saveSM);

}

void CTubing::AddClamp(int x, int y, double rot, double speed)
{
	mClamps.push_back(make_shared<CClamp>(x, y, rot, speed));
}