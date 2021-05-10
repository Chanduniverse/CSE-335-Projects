/**
 * \file Fish.h
 *
 * \author Chandan Aralikatti
 *
 * Class that implements a fish
 */

#pragma once
#include "Item.h"
/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class CFish : public CItem
{
public:
    /// Default constructor (disabled)
    CFish() = delete;

    /// Copy constructor (disabled)
    CFish(const CFish&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    void CFish::Update(double elapsed);

    /// Get the time of the fish
    /// \returns fish time
    double GetTime() { return mTime; }

protected:

    void ChangeSpeed(double x, double y); 

private:
    /// Fish speed in the X direction
    double mSpeedX;

    /// Fish speed in the Y direction
    double mSpeedY;

    /// How long the fish has been alive
    double mTime = 0;

    
protected:
 /**
 * Constructor
 * \param aquarium The aquarium we are in
 * \param filename Filename for the image we use
 */
    CFish::CFish(CAquarium* aquarium, const std::wstring& filename);
};

