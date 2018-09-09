#include <iostream>

using namespace std;

struct Point
{
	int x,y;
	Point(int xv,int yv):x(xv),y(yv){}
};

struct Triangle
{
	Point first,second,third;
	Triangle(Point a,Point b, Point c):first(a),second(b),third(c){}
};
int aXb(Point a, Point b,Point c){
	return ((b.x - a.x)*(c.y - b.y)-(c.x - b.x)*(b.y - a.y));
}
bool inTriangle(Triangle tri,Point p){
	int f = aXb(p,tri.first,tri.second);
	int s = aXb(p,tri.second,tri.third);
	int t = aXb(p,tri.third,tri.first);

	if((f > 0 && s > 0 && t > 0) || (f < 0 && s < 0 && t < 0)){
		return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	Point left(-5,0),right(5,5),up(-5,5);
	Point p(-4,2);
	Triangle tri(left,right,up);
	cout << inTriangle(tri,p) << endl;
	return 0;
}
