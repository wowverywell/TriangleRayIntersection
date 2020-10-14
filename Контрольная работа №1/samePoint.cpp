#include "structures.h"

int samePoint(Point first, Point second, Point third) {
	int x1 = first.coor_x,
		y1 = first.coor_y,
		z1 = first.coor_z,
		
		x2 = second.coor_x,
		y2 = second.coor_y,
		z2 = second.coor_z,

		x3 = third.coor_x,
		y3 = third.coor_y,
		z3 = third.coor_z;

	switch (x1 == x2 & y1 == y2 & z1 == z2) {
	case 1:
		return 0;
		break;
	case 0:
		switch (x2 == x3 && y2 == y3 && z2 == z3) {
			case 1:
				return 0;
				break;
			case 0:
				switch (x1 == x3 && y1 == y3 && z1 == z3) {
					case 1:
						return 0;
						break;
					case 0:
						return 1;
				}
		}
	}
}