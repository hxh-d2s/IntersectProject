#include "pch.h"
#include "CppUnitTest.h"
#include "../IntersectProject/Intersect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectUnitTest1
{
	TEST_CLASS(IntersectUnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Line line(-1, 1, -1);
			line.addIntersection(0, 1);
			int res = line.addIntersection(1, 2);
			Assert::AreEqual(1, res);
		}

		TEST_METHOD(TestMethod2)
		{
			Line line(-1, 1, -1);
			line.addIntersection(0, 1);
			int res = line.addIntersection(0, 1);
			Assert::AreEqual(0, res);
		}

		TEST_METHOD(TestMethod3)
		{
			Line line(-1, 1, -1);
			line.addIntersection(0, 1);
			int res = line.addIntersection(0, 2);
			Assert::AreEqual(0, res);
		}

		TEST_METHOD(TestMethod4)
		{
			Circle circle(0, 0, 2);
			circle.addIntersection(2, 0);
			int res = circle.addIntersection(0, 2);
			Assert::AreEqual(1, res);
		}

		TEST_METHOD(TestMethod5)
		{
			Circle circle(0, 0, 2);
			circle.addIntersection(2, 0);
			int res = circle.addIntersection(2, 0);
			Assert::AreEqual(0, res);
		}

		TEST_METHOD(TestMethod6)
		{
			Circle circle(0, 0, 2);
			circle.addIntersection(2, 0);
			int res = circle.addIntersection(1, 0);
			Assert::AreEqual(0, res);
		}

		TEST_METHOD(TestMethod7)
		{
			Circle circle(0, 0, 2);
			circle.addIntersection(2, 0);
			int res = circle.addIntersection(0, 1);
			Assert::AreEqual(1, res);
		}

		TEST_METHOD(TestMethod8)
		{
			Line line(1, 0, -1);
			line.addIntersection(1, 0);
			int res = line.addIntersection(1, 1);
			Assert::AreEqual(1, res);
		}
	};
}
