#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps=1e-12;
double f(double x)
{
    return sin(x)/x;
}
double simpson(double l,double r)
{
    return (f(l)+f((l+r)/2)*4+f(r))*(r-l)/6;
}
double ars(double l,double r,double s)
{
    double mid=(l+r)/2;
    double sl=simpson(l,mid),sr=simpson(mid,r);
    if(fabs(s-sl-sr)<eps) return sl+sr;
    else return ars(l,mid,sl)+ars(mid,r,sr);
}
int main()
{
    double l,r;
    cin>>l>>r;
    printf("%.6lf\n",ars(l,r,simpson(l,r)));
    return 0;
}
