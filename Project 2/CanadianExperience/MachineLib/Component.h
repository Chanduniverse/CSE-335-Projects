/**
 * \file Component.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */


#pragma once

class CActualMusicBox;

/**
 * Class that represents a component.
 */
class CComponent
{
public:

	CComponent() {}

	/** Set time
	 * \param time */
	virtual void SetTime(double time) {}

	/** Set Music Box
	 * \param box */
	void SetMusicBox(CActualMusicBox* box) { mMusicBox = box; }

	/** Set Position
	 * \param x
	 * \param y */
	virtual void SetPosition(int x, int y) { mPosX = x; mPosY = y; }

	/** Draw the drawable
	 * \param graphics Graphics object to draw on
	 * \param X
	 * \param Y */
	virtual void Draw(Gdiplus::Graphics* graphics, int X, int Y) {};

	/** Get X
	 * \return X */
	int GetX() { return mPosX; }

	/** Get Y
	 * \return Y */
	int GetY() { return mPosY; }

	/** Get Music Box
	 * \return musicbox */
	CActualMusicBox* GetMusicBox() { return mMusicBox; }

private:
	int mPosX = 0; ///< pos X
	int mPosY = 0; ///< pos Y
	CActualMusicBox* mMusicBox = nullptr; ///< music box
};

