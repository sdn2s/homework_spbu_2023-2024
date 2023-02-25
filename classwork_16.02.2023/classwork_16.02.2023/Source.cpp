#include <iostream>
#include <set>
using namespace std;

int main() {

	int x;
	set<int> s; //множество целых чисел s

	while (cin >> x) { //заполняем s, пока не получим пустую строку
		s.insert(x);
	}

	set<int>::iterator i;
	
	for (i = s.begin(); i != s.end(); ++i) {
		cout << *i <<" ";
	}

}