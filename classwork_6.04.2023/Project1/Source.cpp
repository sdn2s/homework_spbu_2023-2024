#include <iostream>
#include <cmath>
#include <future>

// Функция f вычисляет 1/(1+x*x) и возвращает результат
double f(double x) {
    // Создаем задачу для вычисления 1/(1+x*x) в отдельном потоке
    auto task = std::async(std::launch::async, [x] { return 1 / (1 + x * x); });
    // Получаем результат вычислений из объекта future, связанного с задачей
    return task.get();
}


int main() {
    // Входное значение для функции f
    double x = 2.0;
    // Вызываем функцию f и получаем результат вычислений
    double result = f(x);
    
    std::cout << "f(" << x << ") = " << result << std::endl;
    
    return 0;
}
