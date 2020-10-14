#include <iostream>
#include <cmath>
#include "structures.h"

double findSquare(Point A, Point B, Point P) {
	Point AB, AP, vectMult;
	double square;
	AB = { B.coor_x - A.coor_x, B.coor_y - A.coor_y, B.coor_z - A.coor_z };
	AP = { P.coor_x - A.coor_x, P.coor_y - A.coor_y, P.coor_z - A.coor_z };
	vectMult = { AB.coor_y * AP.coor_z - AB.coor_z * AP.coor_y, AB.coor_z * AP.coor_x - AB.coor_x * AP.coor_z, AB.coor_x * AP.coor_y - AB.coor_y * AP.coor_x };

	square = sqrt(pow(vectMult.coor_x, 2) + pow(vectMult.coor_y, 2) + pow(vectMult.coor_z, 2));

	return square;
}

int belong(Point first, Point second, Point third, Point fourth) {

	double squareAll = findSquare(first, second, third),
		square1 = findSquare(first, second, fourth),
		square2 = findSquare(third, second, fourth),
		square3 = findSquare(first, fourth, third);

	if ((square1 + square2 + square3) == squareAll) {
		return 1;
		}
	else {
		return 0;
	}

}