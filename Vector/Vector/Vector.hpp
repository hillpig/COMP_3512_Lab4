#pragma once

#include <iostream>
#include <stdlib.h>

using namespace std;


class Vector {
	double x, y, z;

public:
	Vector();
	Vector(double x, double y, double z);
	Vector(const Vector& otherVector);
	inline double get_X() const;
	inline double get_Y() const;
	inline double get_Z() const;
	inline void set_X(double x);
	inline void set_Y(double y);
	inline void set_Z(double z);
	void clear();
	~Vector();
	friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
	Vector& operator++();
	Vector operator++(int);
	Vector& operator--();
	Vector operator--(int);
	Vector& operator=(Vector rhs);
	friend void swap(Vector& lhs, Vector& rhs);
	Vector& operator+=(const Vector& rhs);
	friend Vector operator+(Vector lhs, const Vector& rhs);
	Vector& operator-=(const Vector& rhs);
	friend Vector operator-(Vector lhs, const Vector& rhs);
	friend double operator*(Vector lhs, const Vector& rhs);
	Vector operator* (double x);
};