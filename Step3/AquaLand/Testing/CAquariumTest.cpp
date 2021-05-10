/**
 * \file CAquariumTest.cpp
 *
 * \author Chandan Aralikatti
 * 
 * Handles Aquarium tests
 */

#include "pch.h"
#include "CppUnitTest.h"

#include "Aquarium.h"
#include "Item.h"
#include "FishBeta.h"
#include "FishNeonTetra.h"
#include "FishMagikarp.h"
#include "FishBashful.h"
#include "DecorCastle.h"
#include <memory>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

/// Fish filename 
const std::wstring FishBetaImageName = L"images/beta.png";

/**
* Create a path to a place to put temporary files
*/
wstring TempPath()
{
	// Create a path to temporary files
	wchar_t path_nts[MAX_PATH];
	GetTempPath(MAX_PATH, path_nts);

	// Convert null terminated string to wstring
	return wstring(path_nts);
}

/**
* Read a file into a wstring and return it.
* \param filename Name of the file to read
* \return File contents
*/
wstring ReadFile(const wstring& filename)
{
	ifstream t(filename);
	wstring str((istreambuf_iterator<char>(t)),
		istreambuf_iterator<char>());

	return str;
}

/**
* Test to ensure an aquarium .aqua file is empty
*/
void TestEmpty(wstring filename)
{
	Logger::WriteMessage(filename.c_str());

	wstring xml = ReadFile(filename);
	Logger::WriteMessage(xml.c_str());

	Assert::IsTrue(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
	Assert::IsTrue(regex_search(xml, wregex(L"<aqua/>")));

}

/**
*  Populate an aquarium with three Beta fish
*/
void PopulateThreeBetas(CAquarium* aquarium)
{
	const unsigned int RandomSeed = 1238197374;
	srand(RandomSeed);

	shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(aquarium);
	fish1->SetLocation(100, 200);
	aquarium->Add(fish1);

	shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(aquarium);
	fish2->SetLocation(400, 400);
	aquarium->Add(fish2);

	shared_ptr<CFishBeta> fish3 = make_shared<CFishBeta>(aquarium);
	fish3->SetLocation(600, 100);
	aquarium->Add(fish3);
}

void TestThreeBetas(wstring filename)
{
	Logger::WriteMessage(filename.c_str());

	wstring xml = ReadFile(filename);
	Logger::WriteMessage(xml.c_str());

	// Ensure three items
	Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

	// Ensure the positions are correct
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));

	// Ensure the types are correct
	Assert::IsTrue(regex_search(xml,
		wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));
}

void TestThreeBetasSpeeds(wstring filename)
{
	Logger::WriteMessage(filename.c_str());

	wstring xml = ReadFile(filename);
	Logger::WriteMessage(xml.c_str());

	// Ensure three items
	Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

	// Ensure the positions are correct
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\" speedx=\"76\\.817529.*\" speedy=\"68\\.7524033.*\"")));
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\" speedx=\"77\\.372356.*\" speedy=\"63\\.917355.*\"")));
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\" speedx=\"50\\.258186.*\" speedy=\"61\\.3565477.*\"")));

	// Ensure the types are correct
	Assert::IsTrue(regex_search(xml,
		wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));
}

void PopulateAllTypes(CAquarium* aquarium)
{
	const unsigned int RandomSeed = 1238197374;
	srand(RandomSeed);

	shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(aquarium);
	fish1->SetLocation(100, 200);
	aquarium->Add(fish1);

	shared_ptr<CFishMagikarp> fish2 = make_shared<CFishMagikarp>(aquarium);
	fish2->SetLocation(400, 400);
	aquarium->Add(fish2);

	shared_ptr<CFishNeonTetra> fish3 = make_shared<CFishNeonTetra>(aquarium);
	fish3->SetLocation(600, 100);
	aquarium->Add(fish3);

	shared_ptr<CFishBashful> fish4 = make_shared<CFishBashful>(aquarium);
	fish4->SetLocation(800, 300);
	aquarium->Add(fish4);

	shared_ptr<CDecorCastle> item1 = make_shared<CDecorCastle>(aquarium);
	item1->SetLocation(900, 300);
	aquarium->Add(item1);
}

void TestAllTypes(wstring filename)
{
	Logger::WriteMessage(filename.c_str());

	wstring xml = ReadFile(filename);
	Logger::WriteMessage(xml.c_str());

	// Ensure five items
	Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*<item.*<item.*</aqua>")));

	// Ensure the positions are correct
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\""))); // mSpeedX=37.075411236915187 mSpeedY=10.192571794793540
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\""))); // {mSpeedX=31.254005554368725 mSpeedY=17.878353221228675 }
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\""))); // {mSpeedX=5.9160130619220554 mSpeedY=4.4575334940641493 }
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"800\" y=\"300\""))); // {mSpeedX=23.195593127231668 mSpeedY=18.248237556077761 }
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"900\" y=\"300\"")));

	// Ensure the types are correct
	Assert::IsTrue(regex_search(xml,
		wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"magikarp\"/><item.* type=\"neontetra\"/><item.* type=\"bashful\"/><item.* type=\"castle\"/></aqua>")));
}

void TestAllSpeeds(wstring filename)
{
	Logger::WriteMessage(filename.c_str());

	wstring xml = ReadFile(filename);
	Logger::WriteMessage(xml.c_str());

	// Ensure five items
	Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*<item.*<item.*</aqua>")));

	// Ensure the positions are correct
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\" speedx=\"76\\.817529.*\" speedy=\"68\\.752403.*\""))); // mSpeedX=37.075411236915187 mSpeedY=10.192571794793540
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\" speedx=\"5\\.9160130.*\" speedy=\"11\\.143833.*\""))); // {mSpeedX=31.254005554368725 mSpeedY=17.878353221228675 }
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\" speedx=\"1378\\.551591.*\" speedy=\"1727\\.6223.*\""))); // {mSpeedX=5.9160130619220554 mSpeedY=4.4575334940641493 }
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"800\" y=\"300\" speedx=\"1\\.60069.*\" speedy=\"1\\.444746.*\""))); // {mSpeedX=23.195593127231668 mSpeedY=18.248237556077761 }
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"900\" y=\"300\""))); // 

	// Ensure the types are correct
	Assert::IsTrue(regex_search(xml,
		wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"magikarp\"/><item.* type=\"neontetra\"/><item.* type=\"bashful\"/><item.* type=\"castle\"/></aqua>")));
}

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

	TEST_CLASS(CAquariumTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCAquariumHitTest)
		{
			CAquarium aquarium;

			Assert::IsTrue(aquarium.HitTest(100, 200) == nullptr,
				L"Testing empty aquarium");

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			Assert::IsTrue(aquarium.HitTest(100, 200) == fish1,
				L"Testing fish at 100, 200");
		}

		TEST_METHOD(TestCAquariumNoImageHitTest)
		{
			CAquarium aquarium;

			Assert::IsTrue(aquarium.HitTest(100, 200) == nullptr,
				L"Testing empty aquarium");

			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			Assert::IsFalse(aquarium.HitTest(200, 200) == fish1,
				L"Testing fish at 200, 200");
		}

		TEST_METHOD(TestCAquariumSave)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create an aquarium
			CAquarium aquarium;

			//
			// First test, saving an empty aquarium
			//
			wstring file1 = path + L"test1.aqua";
			aquarium.Save(file1);

			TestEmpty(file1);

			//
			// Now populate the aquarium
			//

			PopulateThreeBetas(&aquarium);

			wstring file2 = path + L"test2.aqua";
			aquarium.Save(file2);

			TestThreeBetas(file2);
			TestThreeBetasSpeeds(file2);
			//
			// Test all types
			//
			CAquarium aquarium3;
			PopulateAllTypes(&aquarium3);

			wstring file3 = path + L"test3.aqua";
			aquarium3.Save(file3);

			TestAllTypes(file3);

			//
			// Test all speeds
			//
			CAquarium aquarium4;
			PopulateAllTypes(&aquarium4);

			wstring file4 = path + L"test4.aqua";
			aquarium3.Save(file4);

			TestAllSpeeds(file4);
		}

		TEST_METHOD(TestCAquariumClear)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create an aquarium
			CAquarium aquarium;

			//
			// First test, saving an empty aquarium
			//
			wstring file1 = path + L"test1.aqua";
			aquarium.Save(file1);

			TestEmpty(file1);

			//
			// Now populate the aquarium
			//

			PopulateAllTypes(&aquarium);

			wstring file2 = path + L"test2.aqua";
			
			aquarium.Clear();
			aquarium.Save(file2);

			TestEmpty(file2);
		}

		TEST_METHOD(TestCAquariumLoad)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create two aquariums
			CAquarium aquarium, aquarium2;

			//
			// First test, saving an empty aquarium
			//
			wstring file1 = path + L"test1.aqua";

			aquarium.Save(file1);
			TestEmpty(file1);

			aquarium2.Load(file1);
			aquarium2.Save(file1);
			TestEmpty(file1);

			//
			// Now populate the aquarium
			//

			PopulateThreeBetas(&aquarium);

			wstring file2 = path + L"test2.aqua";
			aquarium.Save(file2);
			TestThreeBetas(file2);
			TestThreeBetasSpeeds(file2);

			aquarium2.Load(file2);
			aquarium2.Save(file2);
			TestThreeBetas(file2);
			TestThreeBetasSpeeds(file2);

			//
			// Test all types
			//
			CAquarium aquarium3;
			PopulateAllTypes(&aquarium3);

			wstring file3 = path + L"test3.aqua";
			aquarium3.Save(file3);
			TestAllTypes(file3);
			TestAllSpeeds(file3);

			aquarium2.Load(file3);
			aquarium2.Save(file3);
			
			TestAllTypes(file3);
			TestAllSpeeds(file3);
		}
	};
}