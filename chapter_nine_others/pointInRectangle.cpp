#include <iostream>

using namespace std;

struct Point
{
	int x,y;
	Point(int xv,int yv):x(xv),y(yv){}
};

struct Rectangle
{
	Point left,right,up,down;
	Rectangle(Point a,Point b, Point c, Point d):left(a),right(b),up(c),down(d){}
};
int aXb(Point a, Point b,Point c){
	return ((b.x - a.x)*(c.y - b.y)-(c.x - b.x)*(b.y - a.y));
}
bool inRectangle(Rectangle rec,Point p){
	int a = aXb(p,rec.up,rec.left);
	int b = aXb(p,rec.left,rec.down);
	int c = aXb(p,rec.down,rec.right);
	int d = aXb(p,rec.right,rec.up);
	return (a > 0 && b > 0 && c > 0 && d > 0) || (a < 0 && b < 0 && c < 0 && d < 0);
}

int main(int argc, char const *argv[])
{
	Point left(-5,0),right(5,5),up(-5,5),down(5,0);
	Point p(1,2);
	Rectangle rec(left,right,up,down);
	cout << inRectangle(rec,p) << endl;
	return 0;
}
