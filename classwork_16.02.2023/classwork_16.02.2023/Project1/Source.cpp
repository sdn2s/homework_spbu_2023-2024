#include <iostream>
#include <set>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int x;
	set<int> s; //the set of integers s

	while (cin >> x) { //fill in s until we get an empty string
		s.insert(x);
	}

	set<int>::iterator i;
	
	for (i = s.begin(); i != s.end(); ++i) {
		cout << *i <<" ";
	}

}