#include "Ftbs.h"

#include <cmath>

void Ftbs::insert_point(const Vector &new_p) {
	update_radius(new_p);
	points.insert(new_p);
}

void Ftbs::remove_point(const Vector &delete_p) {
	if (points.erase(delete_p) && delete_p == furthest_point)
		// We just took out the furthest point, so we need to find the new furthest point.
		// Hoping that this will happen on average 1/n of the time.
		recalculate_radius();
}

const Vector Ftbs::center() const {
	return _center;
}

float Ftbs::radius2To(const Vector &p) const {
	return _center.distance2(p);
}

float Ftbs::radius2() const {
	return max_radius2;
}
// Could cache this if it is a common request
float Ftbs::radius() const {
	return std::sqrt(radius2());
}

PointData::const_iterator Ftbs::points_begin() const {
	return points.begin();
}
PointData::const_iterator Ftbs::points_end() const {
	return points.end();
}

void Ftbs::update_radius(const Vector &new_p) {
	float r2_new = radius2To(new_p);
	if (r2_new > max_radius2) {
		max_radius2 = r2_new;
		furthest_point = new_p;
	}
}

void Ftbs::recalculate_radius() {
	max_radius2 = 0;
	furthest_point = Vector::Zero;
	for (auto it = points_begin(); it != points_end(); ++it)
		update_radius(*it);
}

std::ostream& operator<<(std::ostream &o, const Ftbs &ftbs) {
	o << "Ftbs(center: " << ftbs.center() << ", radius: " << ftbs.radius() << ", points: ";
	for (auto it = ftbs.points_begin(); it != ftbs.points_end(); ++it)
		o << *it << " ";
	return o << ")";
}
