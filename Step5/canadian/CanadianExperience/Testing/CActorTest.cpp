#include "pch.h"
#include "CppUnitTest.h"
#include "Actor.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CActorTest)
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

		TEST_METHOD(TestCActorName)
		{
			shared_ptr<CActor> actor = make_shared<CActor>(L"Henry Cavill");

			Assert::IsTrue(actor->GetName() == L"Henry Cavill");
		}

		TEST_METHOD(TestCActorEnabled)
		{
			shared_ptr<CActor> actor = make_shared<CActor>(L"Henry Cavill");

			Assert::IsTrue(actor->IsEnabled());

			actor->SetEnabled(false);

			Assert::IsFalse(actor->IsEnabled());
		}

		TEST_METHOD(TestCActorClickable)
		{
			shared_ptr<CActor> actor = make_shared<CActor>(L"Henry Cavill");

			Assert::IsTrue(actor->IsClickable());

			actor->SetClickable(false);

			Assert::IsFalse(actor->IsClickable());
		}

		TEST_METHOD(TestCActorPosition)
		{
			shared_ptr<CActor> actor = make_shared<CActor>(L"Henry Cavill");

			Assert::AreEqual(0, actor->GetPosition().X);
			Assert::AreEqual(0, actor->GetPosition().Y);

			actor->SetPosition(Gdiplus::Point(1, 2));

			Assert::AreEqual(1, actor->GetPosition().X);
			Assert::AreEqual(2, actor->GetPosition().Y);
		}
	};
}