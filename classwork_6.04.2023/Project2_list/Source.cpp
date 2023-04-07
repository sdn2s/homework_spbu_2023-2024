#include <iostream>
#include <list>
#include <utility>

// ���������� ��� Pair ��� std::pair<int, int>
typedef std::pair<int, int> Pair;

// ������� processList ��������� ������ ��� � ��������� �� �������
void processList(std::list<Pair>& list, void (*f)(Pair&))
{
    // ��������� �� ��������� ������
    for (auto& element : list)
    {
        // �������� �������-�������� ��� ������� �������� ������
        f(element);
    }
}

// ������ ������������� ������� processList
// ������� printPair ��������� ������ �� ���� � ������� �� �������� �� �����
void printPair(Pair& pair)
{
    std::cout << "First: " << pair.first << " Second: " << pair.second << std::endl;
}

int main()
{
    // ������� ������ pairs � ��������� � ���� ����
    std::list<Pair> pairs = { {1, 2}, {3, 4}, {5, 6} };

    // �������� ������� processList, ��������� �� ������ � ��������� �� ������� printPair
    processList(pairs, &printPair);

    return 0;
}
