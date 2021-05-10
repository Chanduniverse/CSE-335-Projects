/**
 * \file FishMagikarp.h
 *
 * \author Chandan Aralikatti
 *
 * Class that implements a Magikarp
 */

#pragma once
#include "Fish.h"
#include<memory>

 /**
  * Implements a Magikarp.
  */
class CFishMagikarp : public CFish
{
public:
    CFishMagikarp(CAquarium* aquarium);

    /// Default constructor (disabled)
    CFishMagikarp() = delete;

    /// Copy constructor (disabled)
    CFishMagikarp(const CFishMagikarp&) = delete;

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    void CFishMagikarp::Update(double elapsed);

    virtual void Draw(Gdiplus::Graphics* graphics);

private:
    /// The image of this fish
    std::unique_ptr<Gdiplus::Bitmap> mGyaradosImage;

    /// tracks if magikarp is evolved or not
    bool evolved = FALSE;
};

