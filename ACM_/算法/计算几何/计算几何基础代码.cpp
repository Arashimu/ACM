#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
//计算几何 
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y) {}
};
typedef Point Vector;
Vector operator + (Vector a,Vector b)  //向量加法 
{
	return Vector(a.x+b.x,a.y+b.y);
}
Vector operator - (Vector a,Vector b)
{
	return Vector(a.x-b.x,a.y-b.y);
}
Vector operator * (Vector a,double p)
{
	return Vector(a.x*p,a.y*p);
}
Vector operator / (Vector a,double p)
{
	return Vector(a.x/p,a.y/p);
}






double Dot (Vector a,Vector b)  //点积 
{
	return a.x*b.x+a.y*b.y;
}
double Length(Vector a){      //模长 
	return sqrt(Dot(a,a));
}
double Angle(Vector a,Vector b) //夹角 
{
	return acos(Dot(a,b)/Length(a)/Length(b));
}
double Cross(Vector a,Vector b)  //叉积
{
	return a.x*b.y-a.y*b.x;
}
double Area(Point a,Point b,Point c)  //A,B,C3点围成三角形的面积 
{
	return abs(Cross(b-a,c-a))/2; 
 } 




//计算凸多边形的有向面积
double ConvexPolygonArea(Point *p,int n) 
{
	double area=0;
	for(int i=1;i<n-1;i++)
	area+=Cross(p[i]-p[0],[i+1]-p[0]);
	return area/2;
 } 
 
 //非凸多边形也可以适用，因为在外面的部分会正负抵消
 
  
