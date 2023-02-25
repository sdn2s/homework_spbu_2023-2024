#include <iostream>
#include <set>
using namespace std;

int main() {
	int x;
	set <int> s, s1, s2;// creating three integer sets
	while (cin >> x) {
		// if an element occurs once, it will remain in s
		if (s.count(x) == 0) { 
			s.insert(x);
		}
		// if an element occurs twice, it falls into s1
		else if (s1.count(x) == 0) {
			s1.insert(x);
		}
		// if an element occurs three times, it falls into s2
		else {
			s2.insert(x);
		}
	}
	// a special form of the for loop for arrays
	for (auto i : s1) { 
		//checking that the element from s1 does not occur for the third time
		if (s2.count(i) == 0) {
			cout << i << " ";
		}
	}


}