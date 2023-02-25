#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s1 = { 1, 3, 5 };
    set<int> s2 = { 2, 4, 6 };

    set<int> s(s1);
    s.insert(s2.begin(), s2.end());

    for (auto i : s) {
            cout << i << " ";
        }
}