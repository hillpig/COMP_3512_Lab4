#include "Vector.hpp"
#include <iostream>

//Default constructor which initializes all three values to 0
Vector::Vector() {
	clear();
}

//Three-parameter constructor that accepts three doubles, x, y, and z
Vector::Vector(double x, double y, double z) : x{ x }, y{ y }, z{z} {

}

//Copy constructr
Vector::Vector(const Vector& otherVector) {
	set_X(otherVector.x);
	set_Y(otherVector.y);
	set_Z(otherVector.z);
}


//Get x,y,z value from the Vector
//Pre: none
//Post: no change to the Vector
//Return: x,y,z value
inline double Vector::get_X() const {
	return x;
}

inline double Vector::get_Y() const{
	return y;
}

inline double Vector::get_Z() const {
	return z;
}


//Set x,y,z value in the Vector
//Pre: none
//Post: x,y,z value is set in the Vector
inline void Vector::set_X(double x) {
	this->x = x;
}

inline void Vector::set_Y(double y) {
	this->y = y;
}

inline void Vector::set_Z(double z) {
	this->z = z;
}


//Set all value in the Vector to 0
//Pre: none
//Post: all value is set to 0
void Vector::clear() {
	set_X(0);
	set_Y(0);
	set_Z(0);
}

//Destructor
//Pre: none
//Post: no change to the Vector
Vector::~Vector() {
	
}

std::ostream& operator<<(std::ostream& out, const Vector& vector) {
	out << "Vector: ( " << vector.x << ", " << vector.y << ", " << vector.z << " )" << "\n";
	return out;
}

//Increment operators in prefix
//Pre: none
//Post: no change to the Vector
//Return: ++ prefix
Vector& Vector::operator++() {
	x++;
	y++;
	z++;
	return *this;
}

//Increment operators in prefix
//Pre: none
//Post: no change to the Vector
//Return: ++ postfix
Vector Vector::operator++(int) {
	Vector temp(*this);
	operator++();
	return temp;
}

//Decrement operators in prefix
//Pre: none
//Post: no change to the Vector
//Return: -- prefix
Vector& Vector::operator--() {
	x--;
	y--;
	z--;
	return *this;
}

//Decrement operators in prefix
//Pre: none
//Post: no change to the Vector
//Return: -- postfix
Vector Vector::operator--(int) {
	Vector temp(*this);
	operator--();
	return temp;
}

//Equal operators in prefix
//Pre: none
//Post: no change to the Vector
//Return: = postfix
Vector& Vector::operator=(Vector rhs) {
	swap(*this, rhs);
	return *this;
}


//Copy and swap the Vector
//Pre: none
//Post: copy and swap the Vector
//Return: Vector after swapping
void swap(Vector& lhs, Vector& rhs) {
	using std::swap;
	swap(lhs.x, rhs.x);
	swap(lhs.y, rhs.y);
	swap(lhs.z, rhs.z);
}

//Addition assignment operator
//Pre: none
//Post: no change to the Vector
//Return: +=
Vector& Vector::operator+=(const Vector& rhs) {
	set_X(x + rhs.x);
	set_Y(y + rhs.y);
	set_Z(z + rhs.z);
	return *this;
}

//Addition operator
//Pre: none
//Post: no change to the Vector
//Return: +
Vector operator+(Vector lhs, const Vector& rhs) {
	return lhs += rhs;
}

//Subtraction assignment operator
//Pre: none
//Post: no change to the Vector
//Return: -=
Vector& Vector::operator-=(const Vector& rhs) {
	set_X(x - rhs.x);
	set_Y(y - rhs.y);
	set_Z(z - rhs.z);
	return *this;
}

//Subtraction operator
//Pre: none
//Post: no change to the Vector
//Return: -
Vector operator-(Vector lhs, const Vector& rhs) {
	return lhs -= rhs;
}

//Multiplication operator
//Pre: none
//Post: no change to the Vector
//Return: *
double operator*(Vector lhs, const Vector& rhs) {
	return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

//Multiplication operator and accecpt a double
//Pre: none
//Post: no change to the Vector
//Return: *
Vector Vector::operator* (double m) {
	Vector multiplier(x*m, y*m, z*m);
	return multiplier;
}

//Overload the operator [] accept an integer 0, 1, or 2
//Pre: none
//Post: no change to the Vector
//Return: return the value of the double stored in the x, y, or z respectively
double Vector::operator[] (int x) const{
	switch (x) {
	case 0:
		return this->x;
	case 1:
		return this->y;
	case 2:
		return this->z;
	default:
		cout << "Null index!" << endl;
		exit(EXIT_SUCCESS);
	}
}