/**
 * \file TimelineDlg.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once

class CTimeline;

/// CTimelineDlg dialog

class CTimelineDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:

	/** Constructor
	*
	* \param pParent
	*/
	CTimelineDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTimelineDlg();

	void SetTimeline(CTimeline* timeline);
	void Take();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMELINEDLG };
#endif

protected:

	/** Data exchange
	*
	* \param pDX
	*/
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	int mNumFrames; ///< number of frames in the animation
	CTimeline* mTimeline = nullptr; ///< The timeline we are editing
	int mFrameRate; ///< frame rate of the animation
};
