#include "Vector.hpp"
#include <iostream>

int main() {
	using std::cout;
	using std::endl;

	cout << "Vector A constructed with default constructor\n";
	Vector test1;
	cout << test1 << endl;

	cout << "Vector B constructed with 3-param constructor (1, 2, 3)\n";
	Vector test2(1,2,3);
	cout << test2 << endl;

	cout << "Setting values in Vector A\n";
	test1.set_X(3);
	test1.set_Y(2);
	test1.set_Z(1);
	cout << test1 << endl;

	cout << "Clearing Vector A\n";
	test1.clear();
	cout << test1 << endl;

	cout << "Vector A += Matrix B\n";
	cout << (test1 += test2) << endl;

	cout << "Vector A--\n";
	cout << (test1--) << endl;

	cout << "Vector A * 2.5\n";
	cout << (test1 * 2.5) << endl;

	cout << "Vector A * Vector B\n";
	cout << (test1 * test2) << endl;

	return 0;
}