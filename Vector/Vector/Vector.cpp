#include "Vector.hpp"
#include <iostream>

Vector::Vector() {
	clear();
}

Vector::Vector(double x, double y, double z) : x{ x }, y{ y }, z{z} {

}

Vector::Vector(const Vector& otherVector) {
	set_X(otherVector.x);
	set_Y(otherVector.y);
	set_Z(otherVector.z);
}

inline double Vector::get_X() const {
	return x;
}

inline double Vector::get_Y() const{
	return y;
}

inline double Vector::get_Z() const {
	return z;
}

inline void Vector::set_X(double x) {
	this->x = x;
}

inline void Vector::set_Y(double y) {
	this->y = y;
}

inline void Vector::set_Z(double z) {
	this->z = z;
}

void Vector::clear() {
	set_X(0);
	set_Y(0);
	set_Z(0);
}

Vector::~Vector() {
	
}

std::ostream& operator<<(std::ostream& out, const Vector& vector) {
	out << "Vector: ( " << vector.x << ", " << vector.y << ", " << vector.z << " )" << "\n";
	return out;
}

Vector& Vector::operator++() {
	x++;
	y++;
	z++;
	return *this;
}

Vector Vector::operator++(int) {
	Vector temp(*this);
	operator++();
	return temp;
}

Vector& Vector::operator--() {
	x--;
	y--;
	z--;
	return *this;
}

Vector Vector::operator--(int) {
	Vector temp(*this);
	operator--();
	return temp;
}
Vector& Vector::operator=(Vector rhs) {
	swap(*this, rhs);
	return *this;
}

void swap(Vector& lhs, Vector& rhs) {
	using std::swap;
	swap(lhs.x, rhs.x);
	swap(lhs.y, rhs.y);
	swap(lhs.z, rhs.z);
}
Vector& Vector::operator+=(const Vector& rhs) {
	set_X(x + rhs.x);
	set_Y(y + rhs.y);
	set_Z(z + rhs.z);
	return *this;
}

Vector operator+(Vector lhs, const Vector& rhs) {
	return lhs += rhs;
}

Vector& Vector::operator-=(const Vector& rhs) {
	set_X(x - rhs.x);
	set_Y(y - rhs.y);
	set_Z(z - rhs.z);
	return *this;
}

Vector operator-(Vector lhs, const Vector& rhs) {
	return lhs -= rhs;
}

double operator*(Vector lhs, const Vector& rhs) {
	return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

Vector Vector::operator* (double m) {
	Vector multiplier(x*m, y*m, z*m);
	return multiplier;
}