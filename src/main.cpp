#include <assert.h>
#include <iostream>
#include <vector>

#include "Ftbs.h"
#include "Vector.h"

void test() {
	Vector center(1, 2, 3);
	Vector oneOff(2, 2, 3);
	Vector halfOff(1.5, 2, 3);

	Ftbs ftbs(center);
	ftbs.insert_point(oneOff);
	assert(ftbs.radius2() == 1);
	ftbs.insert_point(halfOff);
	assert(ftbs.radius2() == 1);

	assert(std::distance(ftbs.points_begin(), ftbs.points_end()) == 2);

	// OK to remove nonexistent point
	ftbs.remove_point(center);
	assert(ftbs.radius2() == 1);
	ftbs.remove_point(oneOff);
	assert(ftbs.radius2() == 0.25);
	ftbs.remove_point(halfOff);
	assert(ftbs.radius2() == 0);

	assert(std::distance(ftbs.points_begin(), ftbs.points_end()) == 0);
}

void test_ctr() {
	Ftbs ftbs(Vector::Zero, std::vector<Vector> { Vector(1, 2, 3), Vector(4, 5, 6) });
	std::cout << ftbs << std::endl;
	Ftbs ftbs2(Vector::Zero, { Vector(6, 5, 4), Vector(3, 2, 1) });
	std::cout << ftbs << std::endl;
}

int main() {
	test();
	test_ctr();
	std::cout << "Tests passed." << std::endl;
	return 0;
}
