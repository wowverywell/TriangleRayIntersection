//������ �������: �������� ����� �� ������������ (������������), ��������� ������������ ������� � �������������,
//����� ���� � ������ ��� �������� --> ���������� �� �������� --> ����������� ��������� ����//


#include <iostream>
#include "structures.h"
#include "findNormal.h"
#include "samePoint.h"
#include "findScalar.h"
#include "menu.h"
#include "intersection.h"
#include "belong.h"
using namespace std;

void program() {
	Figure triangle;
	Point ray, direction, normVect, intersection;
	int valueX, valueY, valueZ, resultSamePoint, scalar, finalResult;
	setlocale(LC_ALL, "Russian");

	do {
		cout << "������� ����� ������ ���������� ������ �����: ";
		cin >> valueX >> valueY >> valueZ;
		triangle.point1 = { valueX, valueY, valueZ };

		cout << "������� ����� ������ ���������� ������ �����: ";
		cin >> valueX >> valueY >> valueZ;
		triangle.point2 = { valueX, valueY, valueZ} ;

		cout << "������� ����� ������ ���������� ������� �����: ";
		cin >> valueX >> valueY >> valueZ;
		triangle.point3 = { valueX, valueY, valueZ} ;
		cout << endl;

		resultSamePoint = samePoint(triangle.point1, triangle.point2, triangle.point3);

		switch (resultSamePoint){
		case 0:
			cout << "����� ������������ �� ����� ���������. ������� ������: " << endl;
				break;
		default:
			break;
		}
	} while (resultSamePoint != 1);

	cout << "������� ���������� ����� ����: ";
	cin >> valueX >> valueY >> valueZ;
	ray = { valueX, valueY, valueZ };

	cout << "������� ���������� ������������� ������� ����: ";
	cin >> valueX >> valueY >> valueZ;
	direction = { valueX, valueY, valueZ };

	normVect = coorNormal(triangle.point1, triangle.point2, triangle.point3);
	scalar = findScalar(direction, normVect);

	if (scalar != 0) {
		cout << "��������� ������������ ������� ��������� ������������ � ������������� ������� ���� ����� " << scalar << endl;
		intersection = intersect(ray, normVect, direction, scalar);
		finalResult = belong(triangle.point1, triangle.point2, triangle.point3, intersection);

		if (finalResult == 1) {
			cout << "��� � ����������� ������������ � ����� M(" << intersection.coor_x << "," << intersection.coor_y << "," << intersection.coor_z << ")" << endl;
		}
	}
	else {
		cout << "��� � ��������� ������������ �� ����� ����� �����������" << endl;
	}

	openMenu();
}