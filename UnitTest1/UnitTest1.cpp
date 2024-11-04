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
			// ���� � ������� (1 -> 2) � (2 -> 3) � ������������
			vector<Edge> edges = { {1, 2}, {2, 3} };
			bool result = isAsymmetric(edges);
			Assert::IsTrue(result, L"���� ������� ���� ������������.");
		}

		TEST_METHOD(TestNonAsymmetricGraph)
		{
			// ���� � ������� (1 -> 2) � (2 -> 1) �� � ������������
			vector<Edge> edges = { {1, 2}, {2, 1} };
			bool result = isAsymmetric(edges);
			Assert::IsFalse(result, L"���� �� ������� ���� ������������.");
		}

		TEST_METHOD(TestTransitiveGraph)
		{
			// ���� � ������� (1 -> 2), (2 -> 3) � (1 -> 3) � ������������
			vector<Edge> edges = { {1, 2}, {2, 3}, {1, 3} };
			int n = 3;
			bool result = isTransitive(edges, n);
			Assert::IsTrue(result, L"���� ������� ���� ������������.");
		}

		TEST_METHOD(TestNonTransitiveGraph)
		{
			// ���� � ������� (1 -> 2) � (2 -> 3) �� � ������������ ��� (1 -> 3)
			vector<Edge> edges = { {1, 2}, {2, 3} };
			int n = 3;
			bool result = isTransitive(edges, n);
			Assert::IsFalse(result, L"���� �� ������� ���� ������������.");
		}
	};
}
