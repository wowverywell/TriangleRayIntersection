//короче сделано: проверка точек на одинаковость (закольцовано), скал€рное произведение нормали и направл€ющего,
//вызов меню в начале при открытии --> направл€ет на алгоритм --> завершаетс€ открытием меню//


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
		cout << "¬ведите через пробел координаты первой точки: ";
		cin >> valueX >> valueY >> valueZ;
		triangle.point1 = { valueX, valueY, valueZ };

		cout << "¬ведите через пробел координаты второй точки: ";
		cin >> valueX >> valueY >> valueZ;
		triangle.point2 = { valueX, valueY, valueZ} ;

		cout << "¬ведите через пробел координаты третьей точки: ";
		cin >> valueX >> valueY >> valueZ;
		triangle.point3 = { valueX, valueY, valueZ} ;
		cout << endl;

		resultSamePoint = samePoint(triangle.point1, triangle.point2, triangle.point3);

		switch (resultSamePoint){
		case 0:
			cout << "“очки треугольника не могут совпадать. ¬ведите заново: " << endl;
				break;
		default:
			break;
		}
	} while (resultSamePoint != 1);

	cout << "¬ведите координаты точки луча: ";
	cin >> valueX >> valueY >> valueZ;
	ray = { valueX, valueY, valueZ };

	cout << "¬ведите координаты направл€ющего вектора луча: ";
	cin >> valueX >> valueY >> valueZ;
	direction = { valueX, valueY, valueZ };

	normVect = coorNormal(triangle.point1, triangle.point2, triangle.point3);
	scalar = findScalar(direction, normVect);

	if (scalar != 0) {
		cout << "—кал€рное произведение нормали плоскости треугольника и направл€ющего вектора луча равно " << scalar << endl;
		intersection = intersect(ray, normVect, direction, scalar);
		finalResult = belong(triangle.point1, triangle.point2, triangle.point3, intersection);

		if (finalResult == 1) {
			cout << "Ћуч и треугольник пересекаютс€ в точке M(" << intersection.coor_x << "," << intersection.coor_y << "," << intersection.coor_z << ")" << endl;
		}
	}
	else {
		cout << "Ћуч и плоскость треугольника не имеют точек пересечени€" << endl;
	}

	openMenu();
}