/*
解决三维偏序问题，按多关键字排序，第三维用树状数组查询 
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 5, M = 2e5 + 5;
int n, m;
struct data
{
    int a, b, c, s, res;
    bool operator < (const data& t)const
    {
        if (a !=t.a) return a<t.a;
        else if (b !=t.b) return b<t.b;
        else return c <t.c;
    }
    bool operator == (const data& t)const
    {
        return a == t.a && b == t.b && c == t.c;
    }
}q[N], w[N];
int tr[M], ans[M];
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int v)
{
    for (int i = x; i < M; i += lowbit(i))  tr[i] += v;
}
int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}
void merge_sort(int l, int r)
{
    if (l >= r)return;
    int mid = (l + r) >> 1;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
        if (q[i].b <= q[j].b) add(q[i].c, q[i].s), w[k++] = q[i++];//w是按b排序
        else q[j].res += query(q[j].c), w[k++] = q[j++];
        
    while (i <= mid) add(q[i].c, q[i].s), w[k++] = q[i++];
    
    while (j <= r)   q[j].res += query(q[j].c), w[k++] = q[j++];
    
    for (i = l; i <= mid; i++) add(q[i].c, -q[i].s);
    for ( i = l, j = 0; j < k; i++, j++) q[i] = w[j];
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n ; i++)
    {
        int a, b, c;
        scanf("%d%d%d",& a, &b,& c);
        q[i] = { a,b,c,1 };
    }
    sort(q, q + n);
    int k = 1;
    for (int i = 1; i < n; i++)
        if (q[i] == q[k - 1]) q[k - 1].s++;
        else q[k++] = q[i];
    merge_sort(0, k - 1);

    for (int i = 0; i < k; i++)
        ans[q[i].res + q[i].s - 1] += q[i].s;
    for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
    return 0;
}



