#include <iostream>
#include <list>
#include <utility>
#include <omp.h>

// Определяем тип Pair как std::pair<int, int>
typedef std::pair<int, int> Pair;

// Функция, которую будем применять к элементам списка
void processPair(Pair& pair)
{
    std::cout << "First: " << pair.first << " Second: " << pair.second << std::endl;
}

// Функция processList принимает список пар и указатель на функцию
void processList(std::list<Pair>& list, void (*f)(Pair&))
{
    // Начало параллельной области
#pragma omp parallel
    {
        // Создаем единичную задачу внутри параллельной области
#pragma omp single
        {
            // Итерируем по элементам списка
            for (auto& element : list)
            {
                // Создаем отдельную задачу для каждого элемента списка
#pragma omp task
                f(element);
            }
        }
    }
}

int main()
{
    // Создаем список pairs и добавляем в него пары
    std::list<Pair> pairs = { {1, 2}, {3, 4}, {5, 6} };

    // Вызываем функцию processList, передавая ей список и указатель на функцию processPair
    processList(pairs, &processPair);

    return 0;
}
