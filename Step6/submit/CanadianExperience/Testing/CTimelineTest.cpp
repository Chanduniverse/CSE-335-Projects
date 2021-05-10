#include "pch.h"
#include "CppUnitTest.h"
#include "Timeline.h"
#include "AnimChannelAngle.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CTimelineTest)
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

		TEST_METHOD(TestCTimelineNumFrames)
		{
			CTimeline line;

			Assert::AreEqual(300, line.GetNumFrames());

			line.SetNumFrames(500);

			Assert::AreEqual(500, line.GetNumFrames());
		}

		TEST_METHOD(TestCTimelineFrameRate)
		{
			CTimeline line;

			Assert::AreEqual(30, line.GetFrameRate());

			line.SetFrameRate(50);

			Assert::AreEqual(50, line.GetFrameRate());
		}

		TEST_METHOD(TestCTimelineCurrentTime)
		{
			CTimeline line;

			Assert::AreEqual(0.0, line.GetTime(), 0.00001);

			line.SetTime(50.0);

			Assert::AreEqual(50.0, line.GetTime(), 0.00001);
		}

		TEST_METHOD(TestCTimelineGetDuration)
		{
			CTimeline timeline;

			// Default value
			Assert::AreEqual(10, timeline.GetDuration(), 0.0001);

			// Changed duration
			timeline.SetFrameRate(375);
			Assert::AreEqual(300.0 / 375.0, timeline.GetDuration(), 0.0001);

			timeline.SetNumFrames(789);
			Assert::AreEqual(789.0 / 375.0, timeline.GetDuration(), 0.0001);
		}

		TEST_METHOD(TestCTimelineGetCurrentFrame)
		{
			CTimeline timeline;

			// Default value
			Assert::AreEqual(0, timeline.GetCurrentFrame());

			// Changed time
			timeline.SetTime(9.27);
			Assert::AreEqual(278, timeline.GetCurrentFrame());
		}

		TEST_METHOD(TestCTimelineAdd)
		{
			CTimeline timeline;
			CAnimChannelAngle channel;

			timeline.AddChannel(&channel);
			Assert::IsTrue(&timeline == channel.GetTimeline());
		}

	};
}