/**
 * \file CardReader.cpp
 *
 * \author Chandan Aralikatti
 */

#include "pch.h"
#include "CardReader.h"
#include <memory>


using namespace std;

//
// These values are for the outputs of the card reader,
// where the tubing attaches.
//

/// Y offset to the first card reader output in pixels
const int OutputOffsetY = -92;

/// X offset to the first card reader output in pixels
const int OutputOffsetX = -35;

/// X spacing for the outputs
const double OutputSpacingX = 10.7;

CCardReader::CCardReader()
{
    mBack.SetImage(L"images/card-reader-back.png");
    mBack.Rectangle(-mBack.GetImageWidth() / 2, 0);
    mFront.SetImage(L"images/card-reader-front.png");
    mFront.Rectangle(-mFront.GetImageWidth() / 2, 0);

    for (int i = 0; i < mNumSources; i++)
    {
        mSources.push_back(make_shared<CAirPump>());
    }


}


void CCardReader::SetPosition(int x, int y)
{
    CComponent::SetPosition(x, y);

    for (int row = 0; row < mNumSources; row++)
    {
        mSources[row]->SetPos(
            (int)(x + OutputOffsetX + OutputSpacingX * row),
            y + OutputOffsetY
        );
    }
}

void CCardReader::Draw(Gdiplus::Graphics* graphics, int X, int Y)
{

    

    
    mBack.DrawPolygon(graphics, X + GetX(), Y + GetY());

    mCard->Draw(graphics, X + GetX(), Y + GetY());

    mFront.DrawPolygon(graphics, X + GetX(), Y + GetY());

    

}

void CCardReader::LoadCard(std::wstring string)
{
    mCard = make_shared<PunchCard>(this);
    mCard->LoadCard(string);

}



void CCardReader::SetTime(double time)
{
    double beat = time * mBeatsPerMinute / 60.0;
    double remainder = fmod(beat, 1);
    mCard->SetColumn((int)beat);
    for (int row = 0; row < mNumSources; row++)
    {
        
        if (mSources[row]->IsValid() && mCard->GetColumn() <= 80)
        {
            bool punched = mCard->IsPunched(mCard->GetColumn(), row);
            if (punched)
                mSources[row]->OnAirPumped(5);
            else
                mSources[row]->OnAirPumped(0);
        }
    }
}