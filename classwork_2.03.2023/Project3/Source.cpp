
#include <iostream>
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

int main() {

	setlocale(LC_ALL, "RU");

	map <int, int> mp;

	mp = fcreate();

	int x;

	while (cin >> x) {
		if (mp.count(x) == 1) {
			cout << x << "->" << mp[x] << endl;
		}
		else {
			cout << x << "->" << x << endl;
		}
	}

	return 0;
}