#pragma once

#include <iostream>

/** 3D Vector. */
class Vector {
public:
	float x, y, z;

	static Vector Zero;

	Vector& operator=(const Vector& v);

	Vector(float _x, float _y, float _z) : x(_x), y(_y), z(_z) { };

	Vector operator-(const Vector& v) const;
	bool operator==(const Vector& v) const;

	float len2() const;
	float distance2(const Vector& v) const;
};

bool operator<(const Vector& v1, const Vector& v2);

std::ostream& operator<<(std::ostream& o, const Vector& v);
