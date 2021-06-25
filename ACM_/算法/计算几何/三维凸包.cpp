#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 205;
const double eps = 1e-11;
int n, m;
bool g[N][N];
double rand_eps() //ȷ��������4������һ��ƽ����
{
    return ((double)rand() / RAND_MAX - 0.5) * eps;
}
struct Point
{
    double x, y, z;
    void shake()
    {
        x += rand_eps(), y += rand_eps(), z += rand_eps();
    }
    Point operator - (const Point& t)
    {
        return { x -t.x, y - t.y, z - t.z };
    }
    double operator & (const Point& t)
    {
        return x * t.x + y * t.y + z * t.z;
    }
    Point operator * (const Point& t)
    {
        return { y * t.z - z * t.y, -(x * t.z - z * t.x), x * t.y - y * t.x };
    }
    double len()
    {
        return sqrt(x*x + y * y + z * z);
    }
}p[N];

struct plane
{
    int v[3]; //ƽ����3������ʱ������ĵ�
    Point norm()//������
    {
        return (p[v[1]] - p[v[0]]) * (p[v[2]] - p[v[0]]);
    }
    double area()
    {
        return norm().len() / 2;
    }
    bool above(Point x)
    {
        return ((x - p[v[0]]) & norm()) >= 0;
    }
}plane[N], np[N];
void get_convex_3d()
{
    plane[m++] = { 0,1,2 }; //����
    plane[m++] = { 2,1,0 }; //����
    for (int i = 3; i < n; i++)   //�Ե�ǰ�ĵ�Ϊ����㣬���ղ�����ƽ�����£��յ�����ɾȥ�����յ��ı��뵱ǰ���γɵ������
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            bool t = plane[j].above(p[i]);
            if (!t) np[cnt++] = plane[j]; //�����ǰ����ĵ��ڵ�ǰƽ�����棬��ô�����̫���ղ��������ƽ��Ҫ����
                for (int k = 0; k < 3; k++)
                    g[plane[j].v[k]][plane[j].v[(k + 1) % 3]] = t;//true���յ���fasle�ղ���
        }
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 3; k++)
            {
                int a = plane[j].v[k], b = plane[j].v[(k + 1) % 3];
                if (g[a][b] && !g[b][a])
                    np[cnt++] = { a,b,i };
            }
        m = cnt;
        for (int j = 0; j < m; j++) plane[j] = np[j];
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
        p[i].shake();
    }

    get_convex_3d();

    double res = 0;
    for (int i = 0; i < m; i++)
        res += plane[i].area();
    printf("%lf",res);
    return 0;

}
