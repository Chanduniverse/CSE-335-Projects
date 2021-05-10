/**
 * \file Shape.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once
#include "Component.h"
#include "Polygon.h"

 /**
  * Class that represents a shape.
  */
class CShape :
    public CComponent
{
public:
	/**
	 * Create a rectangle
	 * \param x Left side X
	 * \param y Bottom left Y
	 * \param wid Width of the rectangle. If not supplied, use an image width
	 * \param hit Height of the rectangle. If not supplied, use an image height
	 */
	void Rectangle(int x, int y, int wid = 0, int hit = 0) { mPolygon.Rectangle(x, y, wid, hit); }

	/**
	 * Set an image we will use as a texture for the polygon
	 * \param filename Image filename
	 */
	void SetImage(std::wstring filename) { mPolygon.SetImage(filename); }

	/**
	 * Get the width of any set image for this polygon. This may not be
	 * the width we actually draw, but is the size of the polygon itself.
	 * @return Width in pixels
	*/
	int GetImageWidth() { return mPolygon.GetImageWidth(); }

	/**
	 * Get the height of any set image for this polygon. This may not be
	 * the height we actually draw, but is the size of the polygon itself.
	 * @return height in pixels
	 */
	int GetImageHeight() { return mPolygon.GetImageHeight(); }

	/**
	 * Set color for the polygon
	 * \param color
	 */
	void SetColor(Gdiplus::Color color) { mPolygon.SetColor(color); }

	/**
	 * Add point to shape
	 * \param x
	 * \param y
	 */
	void AddPoint(int x, int y) { mPolygon.AddPoint(x, y); }

	/**
	 * Center squares the shape
	 * \param size
	 */
	void CenteredSquare(int size) { mPolygon.CenteredSquare(size); }

	/** Draw the drawable
	 * \param graphics Graphics object to draw on
	 * \param X
	 * \param Y */
	virtual void Draw(Gdiplus::Graphics* graphics, int X, int Y) override;

private:
	CPolygon mPolygon; ///< the shape
};

