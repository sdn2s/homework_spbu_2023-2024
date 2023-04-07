#include <iostream>
#include <list>
#include <utility>

// Определяем тип Pair как std::pair<int, int>
typedef std::pair<int, int> Pair;

// Функция processList принимает список пар и указатель на функцию
void processList(std::list<Pair>& list, void (*f)(Pair&))
{
    // Итерируем по элементам списка
    for (auto& element : list)
    {
        // Вызываем функцию-параметр для каждого элемента списка
        f(element);
    }
}

// Пример использования функции processList
// Функция printPair принимает ссылку на пару и выводит ее элементы на экран
void printPair(Pair& pair)
{
    std::cout << "First: " << pair.first << " Second: " << pair.second << std::endl;
}

int main()
{
    // Создаем список pairs и добавляем в него пары
    std::list<Pair> pairs = { {1, 2}, {3, 4}, {5, 6} };

    // Вызываем функцию processList, передавая ей список и указатель на функцию printPair
    processList(pairs, &printPair);

    return 0;
}
