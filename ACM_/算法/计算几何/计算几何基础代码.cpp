#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
//���㼸�� 
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y) {}
};
typedef Point Vector;
Vector operator + (Vector a,Vector b)  //�����ӷ� 
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






double Dot (Vector a,Vector b)  //��� 
{
	return a.x*b.x+a.y*b.y;
}
double Length(Vector a){      //ģ�� 
	return sqrt(Dot(a,a));
}
double Angle(Vector a,Vector b) //�н� 
{
	return acos(Dot(a,b)/Length(a)/Length(b));
}
double Cross(Vector a,Vector b)  //���
{
	return a.x*b.y-a.y*b.x;
}
double Area(Point a,Point b,Point c)  //A,B,C3��Χ�������ε���� 
{
	return abs(Cross(b-a,c-a))/2; 
 } 




//����͹����ε��������
double ConvexPolygonArea(Point *p,int n) 
{
	double area=0;
	for(int i=1;i<n-1;i++)
	area+=Cross(p[i]-p[0],[i+1]-p[0]);
	return area/2;
 } 
 
 //��͹�����Ҳ�������ã���Ϊ������Ĳ��ֻ���������
 
  
