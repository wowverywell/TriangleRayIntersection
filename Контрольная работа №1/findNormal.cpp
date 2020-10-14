#include "structures.h"

Point coorNormal(Point one, Point two, Point three) {
	Point normal;

	int x1 = one.coor_x,
		y1 = one.coor_y,
		z1 = one.coor_z,

		x2 = two.coor_x,
		y2 = two.coor_y,
		z2 = two.coor_z,

		x3 = three.coor_x,
		y3 = three.coor_y,
		z3 = three.coor_z;

	normal.coor_x= ((y2 - y1) * (z3 - z1)) - ((z2 - z1) * (y3 - y1));
	normal.coor_y = -1 * (((x2 - x1) * (z3 - z1)) - ((z2 - z1) * (x3 - x1)));
	normal.coor_z = ((x2 - x1) * (y3 - y1)) - ((y2 - y1) * (x3 - x1));
	normal.freeD = (normal.coor_x * (-1) * x1) + (normal.coor_y * (-1) * y1) + (normal.coor_z * (-1) * z1);

	return normal;
}