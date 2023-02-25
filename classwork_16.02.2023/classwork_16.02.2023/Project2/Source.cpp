#include <iostream>
#include <set>
using namespace std;

int main() {
	int x;
	set <int> s, s1; //creating two numeric sets

	while (cin >> x) {
		if (s.count(x) == 1) { //check the number of occurrences of the element, 
			s1.insert(x);     //and => define in the corresponding set
		}
		else {
			s.insert(x);
		}
	}

	for (auto i : s1) {   // a special form of the for loop for arrays
		cout << i << " ";
	}
}