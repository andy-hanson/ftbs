#pragma once

#include <initializer_list>
#include <set>

#include "Vector.h"

typedef std::set<Vector> PointData;

/**
Fixed, tightly bounding sphere.
Center stays at center and adjusts radius to cover all points inserted.
*/
class Ftbs {
public:
	Ftbs(const Vector& center)
		: _center(center), points(), max_radius2(0), furthest_point(Vector::Zero) { }

	template<typename VectorContainer> Ftbs(const Vector& center, const VectorContainer& c)
		: _center(center), points(c.begin(), c.end()), furthest_point(Vector::Zero) {
		recalculate_radius();
	}

	/** Initialize and insert many points at once. */
	Ftbs(const Vector& center, const std::initializer_list<Vector>& c)
		: _center(center), points(c.begin(), c.end()), furthest_point(Vector::Zero) {
		recalculate_radius();
	}

	void insert_point(const Vector &new_p);
	/** Does nothing if delete_p can not be found. */
	void remove_point(const Vector &delete_p);

	const Vector center() const;

	/** Square of distance to any arbitrary point. */
	float radius2To(const Vector &p) const;
	/** Square of the sphere's radius. (Squared distance to furthest point.) */
	float radius2() const;
	/** Radius of the sphere. */
	float radius() const;

	PointData::const_iterator points_begin() const;
	PointData::const_iterator points_end() const;

private:
	// Defined by:
	const Vector _center;
	PointData points;

	// Cached for perf:
	float max_radius2; // radius2To(furthest_point)
	Vector furthest_point; // The point furthest from _center
	// The above are updated by:
	void update_radius(const Vector &new_p); // O(1)
	void recalculate_radius(); // O(n)
};

std::ostream& operator<<(std::ostream &o, const Ftbs &ftbs);
