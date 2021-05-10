/**
 * \file MusicBox.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

class CActualMusicBox;

#pragma once
#include "Machine.h"
/**
 * Class that represents a music box.
 */
class CMusicBox :
    public CMachine
{
public:
    /// Constructor
    CMusicBox();

    /// Copy constructor/disabled
    CMusicBox(const CMusicBox&) = delete;

    /// Assignment operator/disabled
    void operator=(const CMusicBox&) = delete;

    /**
    * Set the position for the root of the machine
    * \param x X location (pixels)
    * \param y Y location (pixels)
    */
    virtual void SetLocation(int x, int y) override;

    /**
    * Draw the machine at the currently specified location
    * \param graphics GDI+ Graphics object
    */
    virtual void DrawMachine(Gdiplus::Graphics* graphics) override;

    /**
    * Set the current machine animation frame
    * \param frame Frame number
    */
    virtual void SetMachineFrame(int frame) override;

    /**
    * Set the machine number
    * \param machine An integer number. Each number makes a different machine
    */
    virtual void SetMachineNumber(int machine) override;

    /**
     * Get the current machine number
     * \return Machine number integer
     */
    virtual int GetMachineNumber() override;

    /**
     * Get the current frame
     * \return frame
     */
    int GetFrame() { return mFrame; }

    /** Get X
     * \return X */
    int GetX() { return mX; }

    /** Get Y
     * \return Y */
    int GetY() { return mY; }

private:

    std::shared_ptr<CActualMusicBox> mActualMusicBox = nullptr; ///< the music box with the components
    int mX = 200;     ///< Machine X location
    int mY = 200;     ///< Machine Y location
    int mFrame = 0; ///< Current frame
    int mMachine = 1;  ///< Machine number
};