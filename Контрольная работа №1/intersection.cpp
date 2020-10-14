#include "structures.h"

Point intersect(Point pointRay, Point normal, Point direct, int scal) {
	int freeParameter, parameterT;
	Point intersectPoint;

	freeParameter =  (pointRay.coor_x * normal.coor_x) + (pointRay.coor_y * normal.coor_y) + (pointRay.coor_z * normal.coor_z) + normal.freeD;
	parameterT = (-1) * freeParameter / scal; //тут надо почекать, иногда бывает, что T = 0 (скорее всего, когда слкадываются нули из
	// координат)

	intersectPoint.coor_x = direct.coor_x * parameterT + pointRay.coor_x;
	intersectPoint.coor_y = direct.coor_y * parameterT + pointRay.coor_y;
	intersectPoint.coor_z = direct.coor_z * parameterT + pointRay.coor_z;

	return intersectPoint;
}