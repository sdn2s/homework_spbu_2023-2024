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

template <class T1, class T2>
map <T1, T2> func4(map <T1, T2> m1, map <T1, T2> m2)
{
	map <T1, T2> mp;

	auto it = m1.begin();
	auto it2 = m2.begin();
	for (int i = 0; it != m1.end(); it++, it2++, i++) {
		mp[it->first] = it->second + it2->second;
	}
	return mp;
}

int main() {

	setlocale(LC_ALL, "RU");

	map <int, int> m1, m2, mp;

	m1 = fcreate();
	m2 = fcreate();

	mp = func4(m1, m2);

	auto it = mp.begin();
	cout << "Sum: " << endl;
	for (int i = 0; it != mp.end(); it++, i++) {
		cout << "Key: " << it->first << ", result = " << it->second << endl;
	}

	cout << endl;

	return 0;
}