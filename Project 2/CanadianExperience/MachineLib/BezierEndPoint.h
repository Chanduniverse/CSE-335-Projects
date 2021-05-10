/**
 * \file BezierEndPoint.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once

/**
 * Class that represents a bezier end point.
 */
class CBezierEndPoint
{
public:
	/** Set Posistion
	 * \param X 
	 * \param Y */
	void SetPos(int X, int Y) { mPosX = X; mPosY = Y; }

	/** Set Rotation
	 * \param rot */
	void SetRotation(double rot) { mRotation = rot; }

	/** Set Speed
	 * \param speed */
	void SetSpeed(double speed) { mSpeed = speed; }

	/** Get Pos X
	 * \return X */
	int GetPosX() { return mPosX; }

	/** Get Pos Y
	 * \return Y */
	int GetPosY() { return mPosY; }

	/** Get Rotation
	 * \return rotation */
	double GetRotation() { return mRotation; }

	/** Get Speed
	 * \return speed */
	double GetSpeed() { return mSpeed; }

	/** Get Min speed
	 * \return speed */
	double GetMinSpeed() { return mMinSpeed; }

private:
	int mPosX; ///< X pos
	int mPosY; ///< Y pos
	double mRotation = 0; ///< rotation
	double mSpeed = 70; ///< speed
	double mMinSpeed = 30; ///< min speed
};

