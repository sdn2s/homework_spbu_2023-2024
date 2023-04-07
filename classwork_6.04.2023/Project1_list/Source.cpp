#include <iostream>

using namespace std;

// определение структуры Pair
struct Pair {
    int number;    
    bool isPrime;   
};

// функци€ дл€ проверки простоты числа
void processNode(Pair& pair) {
    pair.isPrime = true;    // по умолчанию число считаетс€ простым
    if (pair.number <= 1) { // 1 и меньшие числа не €вл€ютс€ простыми
        pair.isPrime = false;
        return;
    }
    for (int i = 2; i <= pair.number / 2; i++) { // проверка делителей от 2 до половины числа
        if (pair.number % i == 0) { // если делитель найден, число не €вл€етс€ простым
            pair.isPrime = false;
            break;
        }
    }
}


int main() {
    Pair myPair;            // создание экземпл€ра структуры Pair
    myPair.number = 17;     // задание значени€ пол€ number
    processNode(myPair);    // вызов функции processNode дл€ проверки простоты числа
    cout << myPair.number << " is " << (myPair.isPrime ? "prime" : "not prime") << endl; // вывод результата на экран

    return 0;
}
