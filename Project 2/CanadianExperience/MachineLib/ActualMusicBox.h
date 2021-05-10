/**
 * \file ActualMusicBox.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once
#include <vector>
#include <memory>
#include "WavPlayer.h"
class CComponent;
class CMusicBox;
/**
 * Class that represents an actual machine.
 */
class CActualMusicBox
{
public:
	CActualMusicBox();

	/// Copy constructor/disabled
	CActualMusicBox(const CActualMusicBox&) = delete;

	/// Assignment operator/disabled
	void operator=(const CActualMusicBox&) = delete;

	/** Draw the drawable
	 * \param graphics Graphics object to draw on */
	void Draw(Gdiplus::Graphics* graphics);

	/** Add component
	 * \param component */
	void AddComponent(std::shared_ptr<CComponent> component);

	/** Set Music Box
	 * \param box the actual is apart of */
	void SetMusicBox(CMusicBox* box) { mMusicBox = box; }

	/// Get a pointer to the WAVE file player object
	/// \return CWavPlayer object pointer
	CWavPlayer* GetWavPlayer() { return &mWavPlayer; }

private:
	std::vector<std::shared_ptr<CComponent>> mComponents; ///< components of the music box
	CWavPlayer mWavPlayer; ///< wav player
	CMusicBox* mMusicBox = nullptr; ///< music box
};

