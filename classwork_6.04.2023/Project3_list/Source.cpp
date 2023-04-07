#include <iostream>
#include <list>
#include <utility>
#include <omp.h>

// ���������� ��� Pair ��� std::pair<int, int>
typedef std::pair<int, int> Pair;

// �������, ������� ����� ��������� � ��������� ������
void processPair(Pair& pair)
{
    std::cout << "First: " << pair.first << " Second: " << pair.second << std::endl;
}

// ������� processList ��������� ������ ��� � ��������� �� �������
void processList(std::list<Pair>& list, void (*f)(Pair&))
{
    // ������ ������������ �������
#pragma omp parallel
    {
        // ������� ��������� ������ ������ ������������ �������
#pragma omp single
        {
            // ��������� �� ��������� ������
            for (auto& element : list)
            {
                // ������� ��������� ������ ��� ������� �������� ������
#pragma omp task
                f(element);
            }
        }
    }
}

int main()
{
    // ������� ������ pairs � ��������� � ���� ����
    std::list<Pair> pairs = { {1, 2}, {3, 4}, {5, 6} };

    // �������� ������� processList, ��������� �� ������ � ��������� �� ������� processPair
    processList(pairs, &processPair);

    return 0;
}
