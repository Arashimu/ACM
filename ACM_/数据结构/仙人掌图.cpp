/*
将仙人掌图转化为圆方图 
*/ 


#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 12010, M = N * 3;
int n, m, Q, np, cnt;
int head1[N], head2[N];
struct edges
{
    int v, w, nxt;
}e[M];
int dfn[N], low[N], timing;
int s[N], stot[N], fu[N], fw[N];
int fa[N][14], depth[N], d[N];
int A, B;
void add(int head[], int u, int v, int w)
{
    e[cnt] = { v,w,head[u] }, head[u] = cnt++;
}
void build_circle(int x, int y, int z)
{
    int sum = z;
    for (int i = y; i != x; i = fu[i])
    {
        s[i] = sum;
        sum += fw[i];
    }
    s[x] = stot[x] = sum;
    add(head2, x, ++np, 0);
    for (int i = y; i != x; i = fu[i])
    {
        stot[i] = sum;
        add(head2, np, i, min(s[i], sum - s[i]));
    }
}
void tarjan(int u, int from)
{
    dfn[u] = low[u] = ++timing;
    for (int i = head1[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (!dfn[v])
        {
            fu[v] = u, fw[v] = e[i].w;
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
            if(dfn[u]<low[v]) add(head2,u,v,e[i].w);
        }
        else if (i != (from ^ 1)) low[u] = min(low[u], dfn[v]);
    }
    for (int i = head1[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (dfn[u] < dfn[v] && fu[v] != u)
            build_circle(u, v, e[i].w);
    }
}
void dfs_lca(int u, int father)
{
    depth[u] = depth[father] + 1;
    fa[u][0] = father;
    for (int k = 1; k <= 13; k++)
        fa[u][k] = fa[fa[u][k - 1]][k - 1];
    for (int i = head2[u]; ~i; i = e[i].nxt)
    {
        int v = e[i].v, w = e[i].w;
        d[v] = d[u] + w;
        dfs_lca(v, u);
    }
}
int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);
    for (int i = 13; i >= 0; i--)
        if (depth[fa[a][ i]] >= depth[b]) a = fa[a][i];
    if (a == b)return a;
    for (int i = 13; i >= 0; i--)
        if (fa[a][i] != fa[b][i])
            a = fa[a][i], b = fa[b][i];
    A = a, B = b;
    return fa[a][0];
}
int main()
{
    scanf("%d%d%d", &n, &m, &Q);
    np=n;
    memset(head1, -1, sizeof head1);
    memset(head2, -1, sizeof head2);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(head1, u, v, w);
        add(head1, v, u, w);
    }
    tarjan(1, -1);
    dfs_lca(1, 0);
    while (Q--)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        int p = lca(u, v);
        if (p <= n) printf("%d\n", d[u] + d[v] - d[p] * 2);
        else
        {
            int da = d[u] - d[A], db = d[v] - d[B];
            int l = abs(s[A] - s[B]);
            int dm = min(l, stot[A] - l);
            printf("%d\n", da + db + dm);
        }
    }
    return 0;

}


