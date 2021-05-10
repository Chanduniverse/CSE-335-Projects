/**
 * \file Item.h
 *
 * \author Chandan Aralikatti
 *
 * Class that implements item
 */

#pragma once
#include<memory>
#include<string>
#include "XmlNode.h"

class CAquarium;
/**
 * Implements an item
 */
class CItem
{
public:
    virtual ~CItem();
    /// Default constructor (disabled)
    CItem() = delete;

    /// Copy constructor (disabled)
    CItem(const CItem&) = delete;

    /** The X location of the item
     * \returns X location in pixels */
    double GetX() const { return mX; }

    /** The Y location of the item
    * \returns Y location in pixels */
    double GetY() const { return mY; }

    /// Set the item location
    /// \param x X location
    /// \param y Y location
    void SetLocation(double x, double y) { mX = x; mY = y; }

    virtual void Draw(Gdiplus::Graphics* graphics);

    virtual bool HitTest(int x, int y);

    virtual void CItem::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    virtual std::shared_ptr<xmlnode::CXmlNode>
        CItem::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /// Handle updates for animation
    /// \param elapsed The time since the last update
    virtual void Update(double elapsed) {}

    double CalcDist(const CItem&);

    /// Get the aquarium this item is in
    /// \returns Aquarium pointer
    CAquarium* GetAquarium() { return mAquarium; }

    /// Set the mirror status
    /// \param m New mirror flag
    void SetMirror(bool m) { mMirror = m; }

    /// Get the width of the item
    /// \returns item width
    int GetWidth() const { return mItemImage->GetWidth(); }

    /// Get the height of the item
    /// \returns item height
    int GetHeight() const { return mItemImage->GetHeight(); }
    
    /// Gets mirror boolean
    /// \returns item mirrored state
    bool GetMirror() const { return mMirror; }


protected:
    CItem(CAquarium* aquarium, const std::wstring& filename);

    /// The image of this item
    std::unique_ptr<Gdiplus::Bitmap> mItemImage;

private:
    /// The aquarium this item is contained in
    CAquarium* mAquarium;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

    

    bool mMirror = false;   ///< True mirrors the item image

};