#include <iostream>
#include <map>
using namespace std;


map<int, int> fcreate()
{
	map <int, int> mp;
	int key = 0;
	int value = 0;
	int count = 0;


	cout << "count = "; cin >> count;


	for (int i = 0; i < count; i++) {
		cout << "key = "; cin >> key;
		cout << "value = "; cin >> value;

		mp[key] = value;
	}

	return mp;
}

template <class T1, class T2, class T3>
map<T1, T3> func5(map<T1, T2> m1, map<T2, T3> m2)
{
	map <T1, T3> mp;
	for (auto it1 : m1) {
		mp[it1.first] = m2[it1.second];
	}
	return mp;
}

int main() {

	setlocale(LC_ALL, "RU");

	map <int, int> m1, m2, mp;

	m1 = fcreate();
	m2 = fcreate();

	mp = func5(m1, m2);

	cout << "Composition: " << endl;
	for (auto it : mp) {
		cout << "Key: " << it.first << ", result = " << it.second << endl;
	}

	cout << endl;

	return 0;
}