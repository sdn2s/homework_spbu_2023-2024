#include <iostream>

using namespace std;

// ����������� ��������� Pair
struct Pair {
    int number;    
    bool isPrime;   
};

// ������� ��� �������� �������� �����
void processNode(Pair& pair) {
    pair.isPrime = true;    // �� ��������� ����� ��������� �������
    if (pair.number <= 1) { // 1 � ������� ����� �� �������� ��������
        pair.isPrime = false;
        return;
    }
    for (int i = 2; i <= pair.number / 2; i++) { // �������� ��������� �� 2 �� �������� �����
        if (pair.number % i == 0) { // ���� �������� ������, ����� �� �������� �������
            pair.isPrime = false;
            break;
        }
    }
}


int main() {
    Pair myPair;            // �������� ���������� ��������� Pair
    myPair.number = 17;     // ������� �������� ���� number
    processNode(myPair);    // ����� ������� processNode ��� �������� �������� �����
    cout << myPair.number << " is " << (myPair.isPrime ? "prime" : "not prime") << endl; // ����� ���������� �� �����

    return 0;
}
