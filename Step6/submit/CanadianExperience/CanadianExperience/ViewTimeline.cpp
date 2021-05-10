/**
 * \file ViewTimeline.cpp
 *
 * \author Chandan Aralikatti
 */


#include "pch.h"
#include "CanadianExperience.h"
#include "ViewTimeline.h"
#include "DoubleBufferDC.h"
#include "Timeline.h"
#include "Picture.h"
#include <sstream>
#include "MainFrm.h"

using namespace std;
using namespace Gdiplus;


IMPLEMENT_DYNCREATE(CViewTimeline, CScrollView)

/// The window height in pixels
const int WindowHeight = 60;

/// The spacing from the top of the 
/// window to the top of the tick marks in pixels
const int BorderTop = 20;

/// Space to the left of the scale in pixels
const int BorderLeft = 10;

/// Space to the right of the scale in pixels
const int BorderRight = 10;

/// The spacing between ticks on the timeline in pixels
const int TickSpacing = 3;

/// The length of a short tick mark in pixels
const int TickShort = 10;

/// The length of a long tick mark in pixels
const int TickLong = 20;

/** Constructor */
CViewTimeline::CViewTimeline()
{
    mPointer = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/pointer-down.png"));
    assert(mPointer->GetLastStatus() == Ok);
}

/** Destructor */
CViewTimeline::~CViewTimeline()
{
    
}

/**
 * Force an update of this window when the picture changes.
 */
void CViewTimeline::UpdateObserver()
{
    Invalidate();
    UpdateWindow();
}

/** Handle the initial update for this window */
void CViewTimeline::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

    int sbHeight = GetSystemMetrics(SM_CXHSCROLL);
    CSize sizeTotal(200, Height - sbHeight - 20);
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/** Draw this window 
 * \param pDC Device context */
void CViewTimeline::OnDraw(CDC* pDC)
{
    // Get the timeline
    CTimeline* timeline = GetPicture()->GetTimeline();

    // Set the scroll system correctly
    CSize sizeTotal(timeline->GetNumFrames() * TickSpacing + BorderLeft + BorderRight, WindowHeight);
    SetScrollSizes(MM_TEXT, sizeTotal);

    CDoubleBufferDC dbDC(pDC);

    Graphics graphics(dbDC.m_hDC);    // Create GDI+ graphics context

    // TODO: Drawing code goes here

    /*
    Pen pen(Color(0, 128, 0), 1);
    graphics.DrawRectangle(&pen, 10, 10, 200, 60);

    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 16);

    SolidBrush brush(Color(0, 0, 0));
    graphics.DrawString(L"Timeline!",  // String to draw
        -1,         // String length, -1 means it figures it out 
        &font,      // The font to use
        PointF(15, 15),   // Where to draw
        &brush);    // The brush to draw the text with

    CString time = CTime::GetCurrentTime().Format("%H:%M:%S");
    graphics.DrawString(time,  // String to draw
        -1,         // String length, -1 means it figures it out 
        &font,      // The font to use
        PointF(15, 40),   // Where to draw
        &brush);    // The brush to draw the text with
        
    */
    CRect rect;
    GetClientRect(&rect);
    int hit = rect.Height();
    int wid = rect.Width();

    Pen tickpen(Color(0, 0, 0), 1);
    int tickNum = 0;
    bool onSecond = 0;
    FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 12, FontStyleRegular, UnitPoint);
    SolidBrush brush(Color(0, 0, 0));

    while (tickNum < timeline->GetNumFrames() + 1)
    {
        onSecond = (tickNum % timeline->GetFrameRate()) == 0;
        graphics.DrawLine(&tickpen, BorderLeft + (TickSpacing * tickNum), 0.25 * hit, BorderLeft + TickSpacing * tickNum, 0.25 * hit + 10);
        if (onSecond)
        {
            graphics.DrawLine(&tickpen, BorderLeft + (TickSpacing * tickNum), 0.25 * hit, BorderLeft + TickSpacing * tickNum, 0.25 * hit + 20);
            // Convert the tick number to seconds in a string
            std::wstringstream str;
            str << tickNum / timeline->GetFrameRate();
            std::wstring wstr = str.str();

            RectF size;
            PointF origin(0,0);
            graphics.MeasureString(wstr.c_str(), wstr.size(),
                &font, origin, &size);
            PointF location(BorderLeft + (TickSpacing * (tickNum)) - (size.Width/2), 0.25 * hit + 20);
            graphics.DrawString(wstr.c_str(),  // String to draw
                -1,         // String length, -1 means it figures it out 
                &font,      // The font to use
                location,   // Where to draw
                &brush);    // The brush to draw the text with
        }
        graphics.DrawImage(mPointer.get(), BorderLeft + (TickSpacing * (timeline->GetFrameRate() * timeline->GetTime())) - mPointer->GetWidth() / 2, (int)0.25 * hit + 19,
            mPointer->GetWidth(), mPointer->GetHeight());
        tickNum++;
    }


    
    

}


/** Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context 
 * \return FALSE */
BOOL CViewTimeline::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}

/** Handle a press of the keyframe set button on the toolbar
*/
void CViewTimeline::OnEditSetkeyframe()
{
    auto picture = GetPicture();
    for (auto actor : *picture)
    {
        actor->SetKeyframe();
    }
}


 /** Handle the Edit>Delete Keyframe menu option */
 void CViewTimeline::OnEditDeletekeyframe()
 {
     // TODO: Add your command handler code here
     auto picture = GetPicture();
     for (auto actor : *picture)
     {
         actor->DeleteKeyframe();
     }
     picture->SetAnimationTime(picture->GetTimeline()->GetTime());
 }


 // Doxygen sometimes gets confused by these message 
 // maps, since they look like functions. I've found
 // it helps to move them to the end of the file.
 BEGIN_MESSAGE_MAP(CViewTimeline, CScrollView)
	 ON_WM_CREATE()
	 ON_WM_ERASEBKGND()
	 ON_COMMAND(ID_EDIT_SETKEYFRAME, &CViewTimeline::OnEditSetkeyframe)
	 ON_COMMAND(ID_EDIT_DELETEKEYFRAME, &CViewTimeline::OnEditDeletekeyframe)
     ON_WM_LBUTTONDOWN()
     ON_WM_MOUSEMOVE()
 END_MESSAGE_MAP()


 /** L button down
 *
 * Selects pointer
 * \param nFlags
 * \param point
 */
 void CViewTimeline::OnLButtonDown(UINT nFlags, CPoint point)
 {
     // Convert mouse coordinates to logical coordinates
     CClientDC dc(this);
     OnPrepareDC(&dc);
     dc.DPtoLP(&point);

     int x = point.x;

     // Get the timeline
     CTimeline* timeline = GetPicture()->GetTimeline();
     int pointerX = (int)(timeline->GetTime() *
         timeline->GetFrameRate() * TickSpacing + BorderLeft);

     mMovingPointer = x >= pointerX - (int)mPointer->GetWidth() / 2 &&
         x <= pointerX + (int)mPointer->GetWidth() / 2;

     

     __super::OnLButtonDown(nFlags, point);
 }

/** Mouse move
*
* Moves pointer
* \param nFlags
* \param point
*/
 void CViewTimeline::OnMouseMove(UINT nFlags, CPoint point)
 {
     // Convert mouse coordinates to logical coordinates
     CClientDC dc(this);
     OnPrepareDC(&dc);
     dc.DPtoLP(&point);
     // TODO: Add your message handler code here and/or call default
     
     CTimeline* timeline = GetPicture()->GetTimeline();
     double time = timeline->GetTime();
     if (mMovingPointer)
     {
         
         

         if (nFlags & MK_LBUTTON)
         {
             time = (double)(point.x - BorderLeft) / timeline->GetFrameRate() / TickSpacing;
             if (time >= 0 && time <= timeline->GetNumFrames() / timeline->GetFrameRate())
             {
                 GetPicture()->SetAnimationTime(time);
             }
         }
         else
         {
             // When the left button is released, we release the
             // item.
             mMovingPointer = false;
         }
         
     }

     __super::OnMouseMove(nFlags, point);
 }
