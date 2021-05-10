#include "pch.h"
#include "CppUnitTest.h"
#include "PictureObserver.h"
#include "Picture.h"
#include <memory>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	class CPictureObserverMock : public CPictureObserver
	{
	public:
		CPictureObserverMock() : CPictureObserver() {}
		virtual void UpdateObserver() override { mUpdated = true; }

		bool mUpdated = false;
	};

	TEST_CLASS(CPictureObserverTest)
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

		TEST_METHOD(TestCPictureObserverConstruct)
		{
			CPictureObserverMock observer;
		}

		TEST_METHOD(TestCPictureObserverOneObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// And set it for the observer:
			observer.SetPicture(picture);

			picture->UpdateObservers();

			Assert::IsTrue(observer.mUpdated);
		}

		TEST_METHOD(TestCPictureObserverGetPicture)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			Assert::IsFalse(picture == observer.GetPicture());

			observer.SetPicture(picture);

			Assert::IsTrue(picture == observer.GetPicture());
		}

		TEST_METHOD(TestCPictureObserverUpdateObserver)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			CPictureObserverMock observer2;

			Assert::IsFalse(observer.mUpdated);
			Assert::IsFalse(observer2.mUpdated);
			
			observer.SetPicture(picture);
			observer2.SetPicture(picture);

			picture->UpdateObservers();

			Assert::IsTrue(observer.mUpdated);
			Assert::IsTrue(observer2.mUpdated);
		}

		TEST_METHOD(TestCPictureObserverDestroyed)
		{
			// Allocate a CPicture object
			shared_ptr<CPicture> picture = make_shared<CPicture>();

			// Create a mock observer object
			CPictureObserverMock observer;

			// And set it for the observer:
			observer.SetPicture(picture);

			{
				CPictureObserverMock observer2;

				// And set it for the observer:
				observer2.SetPicture(picture);
			}

			picture->UpdateObservers();

			Assert::IsTrue(observer.mUpdated);
		}
	};
}