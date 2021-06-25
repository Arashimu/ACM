#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define x first
#define y second
using namespace std;
const int N = 50005;
const double eps = 1e-8;
typedef pair<int, int>PII;
PII p[N];
int stk[N], use[N], top, n;
PII operator - (PII a, PII b)
{
    return { a.x - b.x,a.y - b.y };
}
int operator * (PII a, PII b)
{
    return a.x * b.y - a.y * b.x;
}
int area(PII a, PII b, PII c)
{
    return (b - a) * (c - a);
}
int get_dist(PII a, PII b)
{
    int x = a.x - b.x;
    int y = a.y - b.y;
    return x * x + y * y;
}
void get_convex() //逆时针存
{
    sort(p, p + n);
    for (int i = 0; i < n; i++)
    {
        while (top >= 2 && area(p[stk[top - 2]], p[stk[top - 1]], p[i]) <= 0)
        {
            if (area(p[stk[top - 2]], p[stk[top - 1]], p[i]) < 0) use[stk[--top]] = 0;
            else top--;
        }
        stk[top++] = i;
        use[i] = 1;
    }
    use[0] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (use[i]) continue;
        while (top >= 2 && area(p[stk[top - 2]], p[stk[top - 1]], p[i]) <= 0)
            top--;
        stk[top++] = i;
    }
    top--;
}
int rotating_calipers()
{
    if (top <= 2)return get_dist(p[0], p[n - 1]);
    int res = 0;
    for (int i = 0, j = 2; i < top; i++)
    {
        auto d = p[stk[i]], e = p[stk[i + 1]];
        while (area(d, e, p[stk[j]]) < area(d, e, p[stk[j + 1]])) j = (j + 1) % top; //通过比面积来比较距离 
        res = max(res, max(get_dist(d, p[stk[j]]), get_dist(e, p[stk[j]])));
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    get_convex();
    printf("%d\n", rotating_calipers());
    return 0;
}
