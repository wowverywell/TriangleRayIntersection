#include <iostream>
#include "program.h"
using namespace std;

void openMenu() {
	setlocale(LC_ALL, "Russian");
	int choice;

	cout << "�������� ������ ����� ����:" << endl;
	cout << "1 - ������ ���������" << endl;
	cout << "2 - ������� ����" << endl;
	cin >> choice;
	
	switch (choice) {
	//��������!!!!!!!!!!!!!!!!!default:
		//break;
	case 1:
		program();
	case 2:
		exit(0);
	}
}

void main() {
	openMenu();
}