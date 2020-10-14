#include <iostream>
#include "program.h"
using namespace std;

void openMenu() {
	setlocale(LC_ALL, "Russian");
	int choice;

	cout << "Выберите нужный пункт меню:" << endl;
	cout << "1 - Запуск программы" << endl;
	cout << "2 - Закрыть окно" << endl;
	cin >> choice;
	
	switch (choice) {
	//доделать!!!!!!!!!!!!!!!!!default:
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