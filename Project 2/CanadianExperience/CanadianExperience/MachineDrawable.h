/**
 * \file MachineDrawable.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once
#include "Drawable.h"
#include "Machine.h"


/**
 * Class that adapts a machine.
 */
class CMachineDrawable :
    public CDrawable
{
public:
    /** Constructor
     * \param name */
    CMachineDrawable(const std::wstring& name);

    /** Draw the drawable
     * \param graphics Graphics object to draw on */
    virtual void Draw(Gdiplus::Graphics* graphics) override;

    /** Destructor */
    virtual ~CMachineDrawable() {}

    /** Set Timeline
     * \param timeline */
    virtual void SetTimeline(CTimeline* timeline) override;

    /** Get Dialog
     * \return Dialog box */
    INT_PTR GetDialog();

    /** Set Machine Frame
     * \param frame */
    void SetMachineFrame(int frame) { mMachine->SetMachineFrame(frame); }

    void SetMachineNumber(int machine);

    /** Default constructor disabled */
    CMachineDrawable() = delete;
    /** Copy constructor disabled */
    CMachineDrawable(const CMachineDrawable&) = delete;
    /** Assignment operator disabled */
    void operator=(const CMachineDrawable&) = delete;

private:
    std::shared_ptr<CMachine> mMachine; ///< machine being adapted

    /// The timeline object
    CTimeline* mTimeline = nullptr;
};

