/**
 * \file Actor.h
 *
 * \author Chandan Aralikatti
 * Class for actors in our drawings
 */

#pragma once

#include "Drawable.h"

#include <string>
#include <memory>
#include <vector>

class CPicture;

 /**
 * Class for actors in our drawings.
 *
 * An actor is some graphical object that consists of
 * one or more parts. Actors can be animated.
 */
class CActor
{
public:
    CActor(const std::wstring& name);

    /** Default constructor disabled */
    CActor() = delete;
    /** Copy constructor disabled */
    CActor(const CActor&) = delete;
    /** Assignment operator disabled */
    void operator=(const CActor&) = delete;

    virtual ~CActor();

    void SetRoot(std::shared_ptr<CDrawable> root);
    void Draw(Gdiplus::Graphics* graphics);
    std::shared_ptr<CDrawable> HitTest(Gdiplus::Point pos);
    void AddDrawable(std::shared_ptr<CDrawable> drawable);

    /** Get the actor name
     * \returns Actor name */
    std::wstring GetName() const { return mName; }

    /** The actor position
    * \returns The actor position as a point */
    Gdiplus::Point GetPosition() const { return mPosition; }

    /** The actor position
    * \param pos The new actor position */
    void SetPosition(Gdiplus::Point pos) { mPosition = pos; }


    /** Actor is enabled
    * \returns enabled status */
    bool IsEnabled() const { return mEnabled; }

    /** Set Actor Enabled
    * \param enabled New enabled status */
    void SetEnabled(bool enabled) { mEnabled = enabled; }

    /** Actor is clickable
    * \returns true if actor is clickable */
    bool IsClickable() const { return mClickable; }

    /** Actor clickable
    * \param clickable New clickable status */
    void SetClickable(bool clickable) { mClickable = clickable; }

    /** The actor picture
    * \returns The picture */
    CPicture* GetPicture() const { return mPicture; }

    void SetPicture(CPicture* pic);

    void SetKeyframe();

    void DeleteKeyframe();

    void GetKeyframe();

    /** The positon animation channel
     * \returns Pointer to animation channel */
    CAnimChannelPosition* GetPositionChannel() { return &mChannel; }

private:
    std::wstring mName; ///< name of the actor
    bool mEnabled = true; ///< Bool that determines wether actor is enabled or not
    Gdiplus::Point mPosition = Gdiplus::Point(0, 0); ///< position of the actor
    bool mClickable = true; ///< Bool that determines wether actor is cliclable or not

    CPicture* mPicture = nullptr; ///< picture the actor belongs to

    /// The root drawable
    std::shared_ptr<CDrawable> mRoot;

    /// The drawables in drawing order
    std::vector<std::shared_ptr<CDrawable>> mDrawablesInOrder;

    /// The animation channel for animating the position of this drawable
    CAnimChannelPosition mChannel;
};