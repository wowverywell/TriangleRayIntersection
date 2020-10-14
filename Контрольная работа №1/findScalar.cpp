#include "structures.h"

int findScalar(Point direct, Point norm) {
	int x1 = direct.coor_x,
		y1 = direct.coor_y,
		z1 = direct.coor_z,

		x2 = norm.coor_x,
		y2 = norm.coor_y,
		z2 = norm.coor_z,

		scal = ((x1 * x2) + (y1 * y2) + (z1 * z2));
		return scal;
}