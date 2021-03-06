/**
 * \file Picture.h
 *
 * \author Chandan Aralikatti
 *
 * The picture we are drawing.
 *
 * There will be one picture object that contains all of 
 * our actors, which then contains the drawables.
 * 
 */

#pragma once
#include "Actor.h"
#include "Timeline.h"
#include <vector>

class CPictureObserver;

/**
* The picture we are drawing.
*
* There will be one picture object that contains all of
* our actors, which then contains the drawables.
*/
class CPicture
{
public:
	CPicture() {}

    /// Copy Constructor (Disabled)
    CPicture(const CPicture&) = delete;

    /// Assignment Operator (Disabled)
    void operator=(const CPicture&) = delete;

    /** The picture size
    * \returns Size */
    Gdiplus::Size GetSize() { return mSize; }

    /** The picture size
    * \param size The new picture size */
    void SetSize(Gdiplus::Size size) { mSize = size; }

    void AddObserver(CPictureObserver* observer);
    void RemoveObserver(CPictureObserver* observer);
    void UpdateObservers();
    void Draw(Gdiplus::Graphics* graphics);

    /** Add actor to picture
    * \param actor to be added */
    void AddActor(std::shared_ptr<CActor> actor);

    /** Get a pointer to the Timeline object
     * \returns Pointer to the Timeline object
     */
    CTimeline* GetTimeline() { return &mTimeline; }

    /** Iterator that iterates over the actors */
    class Iter
    {
    public:
        /** Constructor
         * \param picture The picture we are iterating over
         * \param pos The positon in the collection
         */
        Iter(CPicture* picture, int pos) : mPicture(picture), mPos(pos) {}

        /** Test for end of the iterator
         * \param other The iter being compared to
         * \returns True if we this position equals not equal to the other position */
        bool operator!=(const Iter& other) const
        {
            return mPos != other.mPos;
        }

        /** Get value at current position
         * \returns Value at mPos in the collection */
        std::shared_ptr<CActor> operator *() const { return mPicture->mActors[mPos]; }

        /** Increment the iterator
         * \returns Reference to this iterator */
        const Iter& operator++()
        {
            mPos++;
            return *this;
        }


    private:
        CPicture* mPicture;   ///< picture we are iterating over
        int mPos;       ///< Position in the collection
    };

    /** Get an iterator for the beginning of the collection
     * \returns Iter object at position 0 */
    Iter begin() { return Iter(this, 0); }

    /** Get an iterator for the end of the collection
     * \returns Iter object at position past the end */
    Iter end() { return Iter(this, mActors.size()); }

private:
    /// The picture size
    Gdiplus::Size mSize = Gdiplus::Size(800, 600);

    /// The observers of this picture
    std::vector<CPictureObserver*> mObservers;

    /// The actors of this picture
    std::vector<std::shared_ptr<CActor>> mActors;

    /// The animation timeline
    CTimeline mTimeline;
};

