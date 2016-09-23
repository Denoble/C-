/* ex_memleak.cpp -- lab12 exercise program
*
* This programs has classes Point and Triangle. Triangle consists
* three points. which are reserved separately from dynamic memory.
* Therefore Triangle has three pointers to Points. Memory for the
* Triangle itself has also been reserved from the dynamic memory.
*
* Program can generate an exception at the Nth Point constructor call.
* N is now 4 which means that all those three Points (in Triangle) can
* be created.
*/

#include <iostream>
#include <iostream>
#include <memory>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

// N spesifies which constructor of the Point fails (throws an exception)
#define N 4

// Class definition for Point
class Point {
	friend ostream& operator<<(ostream &out, const Point &point);
public:
	Point(float x0 = 0.0, float y0 = 0.0);
	Point(const Point &p0);
	float getX();
	float getY();
	~Point();
	static int count;
private:
	float x;
	float y;
};
int Point::count = 0;


// Definition for exception class
class Exception {
public:
	Exception(const char *explanation0) { explanation = explanation0; }
	const char *what() const { return explanation; }
private:
	const char *explanation;
};
bool sortVector(const unique_ptr< Point> &pt1, const unique_ptr<  Point> &pt2);
// Main function
int main() {
	try {
		vector<unique_ptr<Point>>points;
		unique_ptr<Point>pt1(new Point(12.0, 15.8));
		unique_ptr<Point>pt2(new Point(10.34, 23.90));
		unique_ptr< Point> pt3(new Point(12.34, 34.12));
		unique_ptr< Point> pt4(new Point(1.99, 2.20));
		
		points.push_back(move(pt1));
		points.push_back(move(pt2));
		points.push_back(move(pt3));
		points.push_back(move(pt4));
		for (int k = 0; k < points.size(); k++){
			cout << points[k]->getX() << " " << points[k]->getY()<<endl;
		}
		sort(points.begin(), points.end(), sortVector);
		cout << endl;
		for (int k = 0; k < points.size(); k++){
			cout << points[k]->getX() << " " << points[k]->getY()<<endl;
		}

	
	}
	catch (Exception e) {
		cout << "Exception explanation is: " << e.what() << endl;
		cout << "Exception is managed now" << endl;
	}
	
	_CrtDumpMemoryLeaks();
	system("PAUSE");
	return EXIT_SUCCESS;
}

//-----------------------------------------------------------------
// Implementation of class Point
Point::Point(float x0, float y0) : x(x0), y(y0) {
	count++;
	if (count > N)
		throw Exception("Does not succeed to create the last apex");
	cout << "Point constructor is done " << (void*)this << endl;
}

Point::~Point() {
	cout << "\nDestructor for Point " << (void*)this << " : ("
		<< x << "," << y << ")" << endl;
}
// Friend functions of Point
ostream &operator<<(ostream & out, const Point &point) {
	out << "(" << point.x << "," << point.y << ")";
	return out;
}
float Point::getX(){
	return this->x;
}
float Point::getY(){
	return this->y;
}
bool sortVector(const unique_ptr< Point> &pt1,const unique_ptr< Point> &pt2){
	
			return sqrt(pow(pt1->getX(), 2) + pow(pt1->getY(), 2))<sqrt(pow(pt2->getX(), 2) + pow(pt2->getY(), 2));
		
			
	}
		
		
		
		
	


