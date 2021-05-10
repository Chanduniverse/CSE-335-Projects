/**
 * \file Aquarium.h
 *
 * \author Chandan Aralikatti
 *
 * Class that implements aquarium
 */

#pragma once
#include<memory>
#include <vector>
#include "Item.h"

/**
 * Implements aquarium
 */
class CAquarium
{
public:
	CAquarium();
	
	void OnDraw(Gdiplus::Graphics* graphics);
	void Add(std::shared_ptr<CItem> item);
	void MoveToFront(std::shared_ptr<CItem> item);
	
	void CAquarium::Save(const std::wstring& filename);
	void CAquarium::Load(const std::wstring& filename);
	void CAquarium::Clear();
	void CAquarium::Update(double elapsed);

	std::shared_ptr<CItem> HitTest(int x, int y);

	/// Get the width of the aquarium
	/// \returns Aquarium width
	int GetWidth() const { return mBackground->GetWidth(); }

	/// Get the height of the aquarium
	/// \returns Aquarium height
	int GetHeight() const { return mBackground->GetHeight(); }

private:
	/// Background image to use
	std::unique_ptr<Gdiplus::Bitmap> mBackground;

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;

	void CAquarium::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

};

