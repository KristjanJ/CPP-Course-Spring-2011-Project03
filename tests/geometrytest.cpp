#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "geometry.h"
#include "myfunctors.h"

using namespace std;

int main (int argc, char* argv[]) {

	// Warning! This test only tests for the presence of methods,
	// not for any kind of validity.

	// Task 1

	// Vector<n>
	// Require default constructor
	Vector<2> v1;
	// Require member coords
	cout << v1.coords.size() << endl;
	// Require constructor with parameters
	Vector<2> v2 (vector<float>());
	// Require distanceFrom method
	float f = v1.distanceFrom(v1);
	// Require toString method
	cout << v1.toString () << endl;

	// Line<V>
	// Require default constructor
	Line< Vector<2> > l1;
	// Require constructor with two parameters
	Line< Vector<2> > l2 (v1, v1);
	// Require members p1 and p2
	cout << l1.p1.toString() << "-" << l1.p2.toString () << endl;
	// Require method length
	f = l1.length();
	// Require toString method
	cout << l1.toString() << endl;

	// Sphere<V>
	// Require default constructor
	Sphere<Vector<2> > c1;
	// Require variable o
	cout << c1.o.toString();
	// Require variable r
	cout << c1.r << endl;
	// Require constructor with vector and a radius
	Sphere< Vector<2> > c2 (v1, 1.0);
	// Require method contains(Vector<n>)
	bool b = c1.contains(v1);
	// Require method contains(Line<Vector<n>>)
	b = c1.contains(l1);
	// Require method scale
	c1.scale(1.0);
	// Require toString method
	cout << c1.toString () << endl;

	// Task 2

	// Require object RandomNumberGenerator;
	RandomNumberGenerator rng;
	// Require operator () of type unsigned long
	unsigned long x = rng();

	// Require object IsSquare
	IsSquare is;
	// Require operator()
	bool c = is((unsigned long)1);

	// Require object SumElements
	SumElements<float> sum;
	// Require operator ()
	sum (1.0);
	// Require method result
	float z = sum.result();


	//Remove this comment to test the bonus tasks

	// Bonus task 1

	// Require default constructor
	Polygon<Vector<2>, 3> triangle;
	// Require constructor with parameter
	Polygon<Vector<2>, 3> triangle2 (vector< Vector<2> >());
	// Require method circumference
	float y = triangle.circumference();
	// Require toString method

	// Require << operators
	cout << v1 << endl;
	cout << l1 << endl;
	cout << c1 << endl;
	cout << triangle << endl;

	//Remove this comment to test the bonus task

	return EXIT_SUCCESS;
}
