#include <iostream>
#include <map>
using namespace std;

// collection creation function
map<int, int> fcreate()
{
	map <int, int> mp;	// creating a collection
	int key = 0;		// collection key
	int value = 0;		// collection value
	int count = 0;		// number of collection items

	// entering a quantity for a collection
	cout << "count = "; cin >> count;

	// entering data from the keyboard
	for (int i = 0; i < count; i++) {
		cout << "key = "; cin >> key;
		cout << "value = "; cin >> value;
		// adding data to a collection
		mp[key] = value;
	}

	return mp;
}

int main() {
	// cyrillic console
	setlocale(LC_ALL, "RU");
	// creating a collection
	map <int, int> mp;
	// function call
	mp = fcreate();

	// data output
	map <int, int> ::iterator it = mp.begin();
	cout << "Данные коллекции: " << endl;
	for (int i = 0; it != mp.end(); it++, i++) {
		cout << i << ") Ключ: " << it->first << ", значение = " << it->second << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}