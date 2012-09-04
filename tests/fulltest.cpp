#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "geometry.h"
#include "myfunctors.h"

void testCompilation(void);
void testGeometry(void);
void testFunctors(void);
void testException(void);

int main(void)
{
    std::cout << "BASIC TEST...\n" << std::endl;
    testCompilation();
    std::cout << "\nTESTING GEOMETRY...\n" << std::endl;
    testGeometry();
    std::cout << "\nTESTING FUNCTORS...\n" << std::endl;
    testFunctors();
    std::cout << "\nTESTING EXCEPTION...\n" << std::endl;
    testException();

	return EXIT_SUCCESS;
}

void testCompilation(void)
{
    using namespace std;

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
	x = x;

	// Require object IsSquare
	IsSquare is;
	// Require operator()
	bool c = is((unsigned long)1);
	c = c;

	// Require object SumElements
	SumElements<float> sum;
	// Require operator ()
	sum (1.0);
	// Require method result
	float z = sum.result();
	z = z;


	//Remove this comment to test the bonus tasks

	// Bonus task 1

	// Require default constructor
	Polygon<Vector<2>, 3> triangle;
	// Require constructor with parameter
	Polygon<Vector<2>, 3> triangle2 (vector< Vector<2> >());
	// Require method circumference
	float y = triangle.circumference();
	y = y;
	// Require toString method

	// Require << operators
	cout << v1 << endl;
	cout << l1 << endl;
	cout << c1 << endl;
	cout << triangle << endl;

	//Remove this comment to test the bonus task
}

void testGeometry(void)
{
    Vector<0> vec01;
    Vector<0> vec02(std::vector<float>(0, 10));
    Vector<0> vec03(std::vector<float>(0, 20));
    std::cout << "VEC<0> 1: " << vec01 << std::endl;
    std::cout << "VEC<0> 2: " << vec02 << std::endl;
    std::cout << "VEC<0> 3: " << vec03 << std::endl;
    std::cout << "VEC<0> 2 distance from VEC<0> 3: " << vec02.distanceFrom(vec03) << std::endl << std::endl;

    Vector<1> vec11;
    Vector<1> vec12(std::vector<float>(1, 10));
    Vector<1> vec13(std::vector<float>(1, 20));
    std::cout << "VEC<1> 1: " << vec11 << std::endl;
    std::cout << "VEC<1> 2: " << vec12 << std::endl;
    std::cout << "VEC<1> 3: " << vec13 << std::endl;
    std::cout << "VEC<1> 2 distance from VEC<1> 3: " << vec12.distanceFrom(vec13) << std::endl << std::endl;

    Vector<2> vec21;
    Vector<2> vec22(std::vector<float>(2, 10));
    Vector<2> vec23(std::vector<float>(2, 20));
    std::cout << "VEC<2> 1: " << vec21 << std::endl;
    std::cout << "VEC<2> 2: " << vec22 << std::endl;
    std::cout << "VEC<2> 3: " << vec23 << std::endl;
    std::cout << "VEC<2> 2 distance from VEC<2> 3: " << vec22.distanceFrom(vec23) << std::endl << std::endl;

    Vector<10> vec101;
    Vector<10> vec102(std::vector<float>(10, 10));
    Vector<10> vec103(std::vector<float>(10, 20));
    std::cout << "VEC<10> 1: " << vec101 << std::endl;
    std::cout << "VEC<10> 2: " << vec102 << std::endl;
    std::cout << "VEC<10> 3: " << vec103 << std::endl;
    std::cout << "VEC<10> 2 distance from VEC<10> 3: " << vec102.distanceFrom(vec103) << std::endl << std::endl;

    Line< Vector<0> > line01;
    Line< Vector<0> > line02(vec02, vec03);
    std::cout << "LINE<0> 1: " << line01 << std::endl;
    std::cout << "LINE<0> 2: " << line02 << std::endl;
    std::cout << "LINE<0> 2 LENGTH: " << line02.length() << std::endl << std::endl;

    Line< Vector<1> > line11;
    Line< Vector<1> > line12(vec12, vec13);
    std::cout << "LINE<1> 1: " << line11 << std::endl;
    std::cout << "LINE<1> 2: " << line12 << std::endl;
    std::cout << "LINE<1> 2 LENGTH: " << line12.length() << std::endl << std::endl;

    Line< Vector<2> > line21;
    Line< Vector<2> > line22(vec22, vec23);
    std::cout << "LINE<2> 1: " << line21 << std::endl;
    std::cout << "LINE<2> 2: " << line22 << std::endl;
    std::cout << "LINE<2> 2 LENGTH: " << line22.length() << std::endl << std::endl;

    Line< Vector<10> > line101;
    Line< Vector<10> > line102(vec102, vec103);
    std::cout << "LINE<10> 1: " << line101 << std::endl;
    std::cout << "LINE<10> 2: " << line102 << std::endl;
    std::cout << "LINE<10> 2 LENGTH: " << line102.length() << std::endl << std::endl;

    Sphere< Vector<0> > sphere01(vec02, 10);
    std::cout << "SPHERE<0>: " << sphere01 << std::endl;
    sphere01.scale(4);
    std::cout << "SPHERE<0> SCALED WITH 4: " << sphere01 << std::endl << std::endl;

    Sphere< Vector<10> > sphere101(vec102, 10);
    std::cout << "SPHERE<10>: " << sphere101 << std::endl;
    std::cout << "CONTAINS: " << std::boolalpha << sphere101.contains(vec103) << std::endl;
    sphere101.scale(4);
    std::cout << "SPHERE<10> SCALED WITH 4: " << sphere101 << std::endl;
    std::cout << "CONTAINS: " << std::boolalpha << sphere101.contains(vec103) << std::endl << std::endl;

    Polygon< Vector<2>, 4 > polygon21;
    std::cout << "POLYGON<2> 1: " << polygon21 << std::endl;
    std::cout << "POLYGON<2> 1 CIRCUMFERENCE: " << polygon21.circumference() << std::endl << std::endl;

    Vector<2> pv1;
    pv1.coords[0] = 5;
    pv1.coords[1] = 5;

    Vector<2> pv2;
    pv2.coords[0] = 5;
    pv2.coords[1] = 10;

    Vector<2> pv3;
    pv3.coords[0] = 10;
    pv3.coords[1] = 10;

    Vector<2> pv4;
    pv4.coords[0] = 10;
    pv4.coords[1] = 5;

    std::vector< Vector <2> > vec;
    vec.push_back(pv1);
    vec.push_back(pv2);
    vec.push_back(pv3);
    vec.push_back(pv4);

    Polygon< Vector<2>, 4 > polygon22(vec);
    std::cout << "POLYGON<2> 2: " << polygon22 << std::endl;
    std::cout << "POLYGON<2> 2 CIRCUMFERENCE: " << polygon22.circumference() << std::endl << std::endl;
}

void testFunctors(void)
{
    RandomNumberGenerator randomGenerator;
    unsigned long random = randomGenerator();
    std::cout << random << std::endl;

    unsigned long longArray[10];
    std::generate_n(longArray, 10, randomGenerator);

    for (int i = 0; i < 10; i++)
    {
        std::cout << longArray[i] << std::endl;
    }

    std::cout << std::endl;

    IsSquare isSquare;

    std::vector<unsigned long> vec(10, 9);
    int x = std::count_if(vec.begin(), vec.end(), isSquare);
    std::cout << "squares: " << x << std::endl;

    std::vector<unsigned long> vec2(10, 345);
    int y = std::count_if(vec2.begin(), vec2.end(), isSquare);
    std::cout << "squares: " << y << std::endl;

    std::vector<int> integers(10, 2593);
    SumElements<int> sum;
    sum = for_each(integers.begin(), integers.end(), sum);
    std::cout << "sum: " << sum.result() << std::endl;

    std::vector<std::string> strings(10, "a");
    SumElements<std::string> sum2;
    sum2 = for_each(strings.begin(), strings.end(), sum2);
    std::cout << "sum_strings(10 * 'a'): " << sum2.result() << std::endl;

}

void testException(void)
{
    try
    {
        Vector<0> vec(std::vector<float>(100, 10));
    }
    catch (std::string& exceptionString)
    {
        std::cout << exceptionString << std::endl;
    }

    try
    {
        Vector<2> pv1;
        Vector<2> pv2;
        Vector<2> pv3;
        Vector<2> pv4;

        std::vector< Vector <2> > vec;
        vec.push_back(pv1);
        vec.push_back(pv2);
        vec.push_back(pv3);
        vec.push_back(pv4);

        Polygon< Vector<2>, 3> polygon(vec);
    }
    catch (std::string& exceptionString)
    {
        std::cout << exceptionString << std::endl;
    }
}
