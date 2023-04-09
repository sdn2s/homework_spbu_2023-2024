#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	ifstream fin("test.txt");

	string f[1000], x[1000], fun[1000];
	string Fun;
	getline(fin, Fun);
	int i = 0, t = 0, pr = 0;
	string name = "";
	char symb;
	while (t == 0) {
		symb = Fun[i];
		if (symb >= 'a' && symb <= 'z') {
			name += symb;
			pr = 1;
		}
		else {
			if (pr == 1) {
				if (name == "sin" || name == "cos" || name == "tg" || name == "ctg" ||
					name == "arcsin" || name == "arccos" || name == "arctg" || name == "arcctg") {
					pr = 0;
					name = "";
				}
				else {
					t = 1;
				}
			}
		}
		i += 1;
	}
	string X = name;

	int k = 0;
	int pos1, pos2, pos3;
	string s;
	while (getline(fin, s)) {
		pos1 = s.find('(');
		f[k] = s.substr(0, pos1);
		pos2 = s.find(')');
		x[k] = s.substr(pos1 + 1, pos2 - pos1 - 1);
		pos3 = s.find('=');
		fun[k] = s.substr(pos3 + 1);
		k += 1;
	}


	string XXX[1000];
	XXX[0] = X;
	int sizeXXX = 0;
	string com;

	int j = 0, cnt;

	while (j <= sizeXXX) {
		for (i = 0; i < k; i++) {
			s = fun[i];
			while (s.find(x[i]) != string::npos) {
				s.replace(s.find(x[i]), x[i].size(), XXX[j]);
			}
			cnt = 0;
			while (Fun.find(s) != string::npos) {
				com = f[i] + '(' + XXX[j] + ')';
				Fun.replace(Fun.find(s), s.size(), com);
				if (cnt == 0) {
					sizeXXX += 1;
					XXX[sizeXXX] = com;
				}
				cnt += 1;
			}
		}
		j += 1;
	}


	ofstream fout("result.txt");
	if (Fun.size() == com.size()) {
		fout << Fun;
	}
	else {
		fout << "невозможно";
	}

	fin.close();
	fout.close();

	return 0;
}