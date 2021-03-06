/**
 * \file MemberReport.h
 *
 * \author Charles B. Owen
 *
 * This is a single report from a member object in the
 * city. It contains a pointer to the tile and a string 
 * generated by the tile.
 */

#pragma once

#include <string>
#include <memory>

class CTile;

/**
 * This is a single report from a member object in the
 * city. It contains a pointer to the tile and a string
 * generated by the tile.
*/
class CMemberReport
{
public:
    CMemberReport(std::shared_ptr<CTile> tile);

    std::wstring Report();

    /**
     * Set the report for this file
     * @param str New report text.
    */
    void SetReport(std::wstring str) { mReport = str; }

private:
    /// Tile this report is for
    std::shared_ptr<CTile>  mTile;

    /// The generated report from the file
    std::wstring mReport;
};

