#include <iostream>
#include <map>
using namespace std;

// ������� �������� ���������
map<int, int> fcreate()
{
	map <int, int> mp;	// �������� ���������
	int key = 0;		// ���� ����������
	int value = 0;		// �������� ���������
	int count = 0;		// ����� ��������� ���������

	// ���� ���������� ��� ���������
	cout << "count = "; cin >> count;

	// ���� ������ � ����������
	for (int i = 0; i < count; i++) {
		cout << "key = "; cin >> key;
		cout << "value = "; cin >> value;
		// ���������� ������ � ���������
		mp[key] = value;
	}

	return mp;
}

int main() {
	// ��������� �������
	setlocale(LC_ALL, "RU");
	// �������� ���������
	map <int, int> mp;
	// ����� �������
	mp = fcreate();

	// ����� ������
	map <int, int> ::iterator it = mp.begin();
	cout << "������ ���������: " << endl;
	for (int i = 0; it != mp.end(); it++, i++) {
		cout << i << ") ����: " << it->first << ", �������� = " << it->second << endl;
	}

	cout << endl;
	system("pause");
	return 0;
}