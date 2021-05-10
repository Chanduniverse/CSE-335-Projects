/**
 * \file CardReader.h
 *
 * \author Chandan Aralikatti
 *
 * 
 */

#pragma once
#include "Component.h"
#include "Polygon.h"

#include "AirPump.h"

/**
 * Class that represents the card reader.
 */
class CCardReader :
    public CComponent
{
public:
    /** Draw the drawable
     * \param graphics Graphics object to draw on 
     * \param X
     * \param Y */
    virtual void Draw(Gdiplus::Graphics* graphics, int X, int Y) override;

    /** Set Time
     * 
     *  the update function
     *
     * \param time */
    virtual void SetTime(double time);

    /** Set Position
     * \param x
     * \param y */
    virtual void SetPosition(int x, int y) override;

    /** Load Card
     * \param string */
    void LoadCard(std::wstring string);

    CCardReader();

    /**
    * Get an air pump.
    * @param i Source index 0-9
    * @return Pointer to CAirPump object.
    */
    std::shared_ptr<CAirPump> GetSource(int i) { return mSources[i]; }

    /**
     * Class that represents a punchcard
     */
    class PunchCard
    {
    public:

        /// Width to draw the card on the screen in pixels
        const int CardWidth = 132;

        /// Height to draw the card on the screen in pixels
        const int CardLength = 297;

        /// Amount of offset the center of the card so it will
        /// appear at the right place relative to the card reader.
        const int CardOffsetX = 126;

        /// Y dimension of the offset
        const int CardOffsetY = 65;

        // These values are all for the underlying image. They
        // can be used for find the punches.

        /// Width of a card column in pixels
        const int CardColumnWidth = 10;

        /// Height of a card row in pixels
        const int CardRowHeight = 29;

        /// X offset for the first column (left side)
        const int CardColumn0X = 24;

        /// Y offset to the first row (0's)
        /// There are actually two rows above this that can be used
        const int CardRow0Y = 78;

        /// Width of a punched hole
        const int CardPunchWidth = 8;

        /// Height of a punched hole
        const int CardPunchHit = 20;

        /// Any average luminance below this level is considered a punched hole
        const double CardPunchLuminance = 0.1;

        /** The Constructor
         * \param reader */
        PunchCard(CCardReader* reader) : mReader(reader) {}
        /** Default constructor disabled */
        PunchCard() = delete;
        /** Copy constructor disabled */
        PunchCard(const PunchCard&) = delete;
        /** Assignment operator disabled */
        void operator=(const PunchCard&) = delete;

        /** Load the card
        * \param string the filename*/
        void LoadCard(std::wstring string) { mCard.SetImage(string); mCard.Rectangle(CardOffsetX, CardOffsetY, CardLength, CardWidth); mCard.SetRotation(-0.25); };
        
        /** Draw the drawable
         * \param graphics Graphics object to draw on
         * \param X
         * \param Y */
        void Draw(Gdiplus::Graphics* graphics, int X, int Y) { mCard.DrawPolygon(graphics, X, Y + (mColumn - 1) * ((double)CardLength / mCard.GetImageWidth()) * CardColumnWidth); };

        /** Set Column
        * \param col */
        void SetColumn(int col) { mColumn = col; }

        /** Get Column
        * \return col */
        int GetColumn() { return mColumn; }

         /**
         * Determine if a hole is punched in the card.
         * @param column Column on the card, from 0 (left of first column) to 80 (last column)
         * @param row Row on the card, -2 to 9.
         * @return True if hole is punched at column, row
         */
        bool PunchCard::IsPunched(int column, int row)
        {
            auto luminance = mCard.AverageLuminance(CardColumn0X + (column - 1) * CardColumnWidth,
                CardRow0Y + CardRowHeight * row, CardPunchWidth, CardPunchHit);
            return luminance < CardPunchLuminance;
        }

        

    private:
        
        CPolygon mCard; ///< card image
        int mColumn = 1; ///< column of card
        /// The reader this card is associated with
        CCardReader* mReader; ///< card reader
    };

private:
    CPolygon mFront; ///< front of card reader
    CPolygon mBack; ///< back of card reader
    int mBeatsPerMinute = 180; ///< bpm
    int mNumSources = 10; ///< num of pumps
    std::shared_ptr<PunchCard> mCard = nullptr; ///< the punch card
    /// The air pumps to drive things
    std::vector<std::shared_ptr<CAirPump>> mSources;
};

