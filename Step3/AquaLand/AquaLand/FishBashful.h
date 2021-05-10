/**
 * \file FishBashful.h
 *
 * \author Chandan Aralikatti
 *
 * Class that implements a Bashful fish
 */

#pragma once
#include "Fish.h"
#include<memory>

 /**
  * Implements a Bashful fish.
  */
class CFishBashful : public CFish
{
public:
    CFishBashful(CAquarium* aquarium);

    /// Default constructor (disabled)
    CFishBashful() = delete;

    /// Copy constructor (disabled)
    CFishBashful(const CFishBashful&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

private:
    /// image of our fish blushing
    std::unique_ptr<Gdiplus::Bitmap> mBashfulImage;

    /// keep track of bashfulness
    bool mBashful = FALSE;
};

