/**
 * \file CItemTest.cpp
 *
 * \author Chandan Aralikatti
 * 
 * Handles item tests
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


	};

	TEST_CLASS(CItemTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCItemConstruct)
		{
			CAquarium aquarium;
			CItemMock item(&aquarium);
		}

		TEST_METHOD(TestCItemGettersSetters)
		{
			// Construct an item to test
			CAquarium aquarium;
			CItemMock item(&aquarium);

			// Test initial values
			Assert::AreEqual(0, item.GetX(), 0);
			Assert::AreEqual(0, item.GetY(), 0);

			// Test SetLocation, GetX, and GetY
			item.SetLocation(10.5, 17.2);
			Assert::AreEqual(10.5, item.GetX(), 0.0001);
			Assert::AreEqual(17.2, item.GetY(), 0.0001);

			// Test a second with with different values
			item.SetLocation(-72, -107);
			Assert::AreEqual(-72, item.GetX(), 0.0001);
			Assert::AreEqual(-107, item.GetY(), 0.0001);
		}

		TEST_METHOD(TestCItemHitTest)
		{
			// Create a item to test
			CAquarium aquarium;
			CItemMock item(&aquarium);

			// Give it a location
			// Always make the numbers different, in case they are mixed up
			item.SetLocation(100, 200);

			// Center of the item should be a true
			Assert::IsTrue(item.HitTest(100, 200));

			// Left of the item
			Assert::IsFalse(item.HitTest(10, 200));

			// Right of the item
			Assert::IsFalse(item.HitTest(200, 200));

			// Above the item
			Assert::IsFalse(item.HitTest(100, 0));

			// Below the item
			Assert::IsFalse(item.HitTest(100, 300));

			// Of item transparent pixel
			Assert::IsFalse(item.HitTest(100 - 125 / 2 + 17, 200 - 117 / 2 + 16));
		}

		TEST_METHOD(TestCItemTopHitTest)
		{
			// Create two item to test
			CAquarium aquarium;
			shared_ptr<CItemMock> item1 = make_shared<CItemMock>(&aquarium);
			shared_ptr<CItemMock> item2 = make_shared<CItemMock>(&aquarium);

			// Set their locations
			item1->SetLocation(100, 200);
			item2->SetLocation(100, 200);
			aquarium.Add(item1);
			aquarium.Add(item2);

			// Fish 2 above Fish 1
			Assert::IsTrue(aquarium.HitTest(100, 200) == item2);
		}

	};
}