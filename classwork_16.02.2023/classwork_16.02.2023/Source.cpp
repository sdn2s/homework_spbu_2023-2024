#include <iostream>
#include <set>
using namespace std;

int main() {

	int x;
	set<int> s; //��������� ����� ����� s

	while (cin >> x) { //��������� s, ���� �� ������� ������ ������
		s.insert(x);
	}

	set<int>::iterator i;
	
	for (i = s.begin(); i != s.end(); ++i) {
		cout << *i <<" ";
	}

}