// TimelineDlg.cpp : implementation file
//

#include "pch.h"
#include "CanadianExperience.h"
#include "TimelineDlg.h"
#include "afxdialogex.h"
#include "Timeline.h"

// CTimelineDlg dialog

IMPLEMENT_DYNAMIC(CTimelineDlg, CDialog)

CTimelineDlg::CTimelineDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_TIMELINEDLG, pParent)
	, mNumFrames(0)
{

}

CTimelineDlg::~CTimelineDlg()
{
}

void CTimelineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUMFRAMES, mNumFrames);
	DDV_MinMaxInt(pDX, mNumFrames, 10, 10000);
}

/**
* Pass a timeline object to this dialog box class.
* \param timeline The timeline object.
*/
void CTimelineDlg::SetTimeline(CTimeline* timeline)
{
	mTimeline = timeline;
	mNumFrames = mTimeline->GetNumFrames();
}

/** Transfer dialog values to the Timeline object
*/
void CTimelineDlg::Take()
{
	mTimeline->SetNumFrames(mNumFrames);
}

BEGIN_MESSAGE_MAP(CTimelineDlg, CDialog)
END_MESSAGE_MAP()


// CTimelineDlg message handlers
