#include <iostream>
#include <set>
using namespace std;

template <typename T>
set<T> ob(set<T> a, set<T> b) {
	set<T> s(a);
	s.insert(b.begin(), b.end());
	set<T> k(s);
	for (auto i : k) {
		cout << i << " ";
	}
	return s;
}

int main() {

	set<int> s1 = { 1, 3, 5 };

	set<int> s2 = { 2, 4, 6 };

	ob(s1, s2);
}