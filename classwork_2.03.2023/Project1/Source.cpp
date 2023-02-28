#include <iostream>
#include <map>
using namespace std;

int main() {
	int i = 1;

	int k;

	int cnt = 0;

	map<int, int> m;

	map<int, int>::const_iterator it = m.begin();

	while (cin >> k) {
		m[k] = i;
		i += 1;
	}
	for (auto x : m) {
		cout << x.first << " -> " << x.second << endl;
	}

}