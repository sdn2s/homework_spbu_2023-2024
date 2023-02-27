#include <iostream>
#include <map>
using namespace std;

// функция создания коллекции
map<int, int> fcreate()
{
	map <int, int> mp;	// создание коллекции
	int key = 0;		// ключ коллеклции
	int value = 0;		// значение коллекции
	int count = 0;		// колво элементов коллекции

	// ввод количества для коллекции
	cout << "count = "; cin >> count;

	// ввод данных с клавиатуры
	for (int i = 0; i < count; i++) {
		cout << "key = "; cin >> key;
		cout << "value = "; cin >> value;
		// добавление данных в коллекцию
		mp[key] = value;
	}

	return mp;
}

int main() {
	// кириллица консоли
	setlocale(LC_ALL, "RU");
	// создание коллекции
	map <int, int> mp;
	// вызов функции
	mp = fcreate();

	// вывод данных
	map <int, int> ::iterator it = mp.begin();
	cout << "Данные коллекции: " << endl;
	for (int i = 0; it != mp.end(); it++, i++) {
		cout << i << ") Ключ: " << it->first << ", значение = " << it->second << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}