#include "Vector.h"

Vector Vector::Zero = Vector(0, 0, 0);

Vector& Vector::operator=(const Vector& v) {
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

Vector Vector::operator-(const Vector& v) const {
	return Vector(x - v.x, y - v.y, z - v.z);
}

bool Vector::operator==(const Vector& v) const {
	return x == v.x && y == v.y && z == v.z;
}

float Vector::len2() const {
	return x * x + y * y + z * z;
}

float Vector::distance2(const Vector& v) const {
	return (*this - v).len2();
}

std::ostream& operator<<(std::ostream& o, const Vector& v) {
	return o << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

// Comparison for being stored in a set
bool operator<(const Vector& v1, const Vector& v2) {
	if (v1.x < v2.x) return true;
	if (v1.x > v2.x) return false;

	if (v1.y < v2.y) return true;
	if (v1.y > v2.y) return false;

	return v1.z < v2.z;
}
