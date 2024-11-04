#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab14_PDC/Lab14_PDC.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestAsymmetricGraph)
		{
			// Граф з ребрами (1 -> 2) і (2 -> 3) є асиметричним
			vector<Edge> edges = { {1, 2}, {2, 3} };
			bool result = isAsymmetric(edges);
			Assert::IsTrue(result, L"Граф повинен бути асиметричним.");
		}

		TEST_METHOD(TestNonAsymmetricGraph)
		{
			// Граф з ребрами (1 -> 2) і (2 -> 1) не є асиметричним
			vector<Edge> edges = { {1, 2}, {2, 1} };
			bool result = isAsymmetric(edges);
			Assert::IsFalse(result, L"Граф не повинен бути асиметричним.");
		}

		TEST_METHOD(TestTransitiveGraph)
		{
			// Граф з ребрами (1 -> 2), (2 -> 3) і (1 -> 3) є транзитивним
			vector<Edge> edges = { {1, 2}, {2, 3}, {1, 3} };
			int n = 3;
			bool result = isTransitive(edges, n);
			Assert::IsTrue(result, L"Граф повинен бути транзитивним.");
		}

		TEST_METHOD(TestNonTransitiveGraph)
		{
			// Граф з ребрами (1 -> 2) і (2 -> 3) не є транзитивним без (1 -> 3)
			vector<Edge> edges = { {1, 2}, {2, 3} };
			int n = 3;
			bool result = isTransitive(edges, n);
			Assert::IsFalse(result, L"Граф не повинен бути транзитивним.");
		}
	};
}
