#include "pch.h"
#include "CppUnitTest.h"
#include "PolyDrawable.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CPolyDrawableTest)
	{
	public:

		/** Compares two colors
		* \param a Color a
		* \param b Color b
		* \returns true if colors are the same */
		bool CompareColors(Gdiplus::Color a, Gdiplus::Color b)
		{
			if (a.GetValue() == b.GetValue())
			{
				return true;
			}
		}

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}

		TEST_METHOD(TestCPolyDrawableName)
		{
			shared_ptr<CPolyDrawable> drawable = make_shared<CPolyDrawable>(L"poly");

			Assert::IsTrue(drawable->GetName() == L"poly");
		}

		TEST_METHOD(TestCPolyDrawableColor)
		{
			shared_ptr<CPolyDrawable> drawable = make_shared<CPolyDrawable>(L"poly");

			Assert::IsTrue(CompareColors(drawable->GetColor(), Gdiplus::Color::Black));

			drawable->SetColor(Gdiplus::Color::Blue);

			Assert::IsTrue(CompareColors(drawable->GetColor(), Gdiplus::Color::Blue));
		}
	};
}