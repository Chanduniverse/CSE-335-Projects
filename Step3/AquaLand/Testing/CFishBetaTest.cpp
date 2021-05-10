/**
 * \file CFishBetaTest.cpp
 *
 * \author Chandan Aralikatti
 * 
 * Handles beta fish tests
 */

#include "pch.h"
#include "CppUnitTest.h"

#include "Aquarium.h"
#include "Item.h"
#include "FishBeta.h"
#include <memory>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

/// Fish filename 
const std::wstring FishBetaImageName = L"images/beta.png";

namespace Testing
{
	/** Mock class for testing CItem */
	class CItemMock : public CItem
	{
	public:
		/** Constructor
		 * \param aquarium The aquarium this is a member of */
		CItemMock(CAquarium* aquarium) :
			CItem(aquarium, FishBetaImageName) {}

		/** Draw the item
		 * \param graphics The graphics context to draw on */
		virtual void Draw(Gdiplus::Graphics* graphics) {}

		/** Test to see if we clicked on this item
		 * \param x X location
		 * \param y Y location
		 * \returns true if we did click on the item */
		virtual bool HitTest(int x, int y) { return false; }

	};

	TEST_CLASS(CFishBetaTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCFishBetaConstruct)
		{
			CAquarium aquarium;
			CFishBeta FishBeta(&aquarium);
		}

		

	};
}