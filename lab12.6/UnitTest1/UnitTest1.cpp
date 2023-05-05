#include "pch.h"
#include "CppUnitTest.h"
#include "../lab12.6/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyTests
{
    TEST_CLASS(TestQueue)
    {
    public:

        TEST_METHOD(TestEnqueue)
        {
            Elem* first = NULL;
            Elem* last = NULL;

            enqueue(first, last, 5);

            Assert::AreEqual(first->info, 5);
            Assert::AreEqual(last->info, 5);
        }
    };
}
