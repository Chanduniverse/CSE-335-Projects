#include "pch.h"
#include "CppUnitTest.h"
#include "Drawable.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	class CDrawableMock : public CDrawable
	{
	public:
		CDrawableMock(const std::wstring& name) : CDrawable(name) {}

		virtual void Draw(Gdiplus::Graphics* graphics) override {}
		virtual bool HitTest(Gdiplus::Point pos) override { return false; }
	};

	TEST_CLASS(CDrawableTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestNothing)
		{
			// This is an empty test just to ensure the system is working
		}

		TEST_METHOD(TestCDrawableName)
		{
			shared_ptr<CDrawableMock> drawable = make_shared<CDrawableMock>(L"element");

			Assert::IsTrue(drawable->GetName() == L"element");
		}

		TEST_METHOD(TestCDrawablePosition)
		{
			shared_ptr<CDrawableMock> drawable = make_shared<CDrawableMock>(L"element");

			Assert::AreEqual(0, drawable->GetPosition().X);
			Assert::AreEqual(0, drawable->GetPosition().Y);

			drawable->SetPosition(Gdiplus::Point(1, 2));

			Assert::AreEqual(1, drawable->GetPosition().X);
			Assert::AreEqual(2, drawable->GetPosition().Y);
		}

		TEST_METHOD(TestCDrawableRotation)
		{
			shared_ptr<CDrawableMock> drawable = make_shared<CDrawableMock>(L"element");

			Assert::AreEqual(0.0, drawable->GetRotation(), 0.00001);

			drawable->SetRotation(0.1);

			Assert::AreEqual(0.1, drawable->GetRotation(), 0.00001);
		}

		TEST_METHOD(TestCDrawableAssociation)
		{
			CDrawableMock body(L"Body");
			auto arm = std::make_shared<CDrawableMock>(L"Arm");
			auto leg = std::make_shared<CDrawableMock>(L"Leg");

			Assert::IsNull(arm->GetParent());
			Assert::IsNull(leg->GetParent());

			body.AddChild(arm);
			body.AddChild(leg);

			Assert::IsTrue(arm->GetParent() == &body);
			Assert::IsTrue(leg->GetParent() == &body);
		}
	};
}