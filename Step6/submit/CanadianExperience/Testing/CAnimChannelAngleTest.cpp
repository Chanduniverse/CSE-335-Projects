#include "pch.h"
#include "CppUnitTest.h"
#include "AnimChannelAngle.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace Testing
{
	TEST_CLASS(CAnimChannelAngleTest)
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

		TEST_METHOD(TestCAnimChannelAngle)
		{
			shared_ptr<CAnimChannelAngle> channel = make_shared<CAnimChannelAngle>();

			channel->SetName(L"anime");

			Assert::IsTrue(channel->GetName() == L"anime");

			channel->SetName(L"SomethingElse");

			Assert::IsTrue(channel->GetName() == L"SomethingElse");

		}

	};
}