#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 10005;
int r[N], l[N], u[N], d[N], s[N], col[N], row[N], idx;
int ans[N], st[N];
int n, m;
void init()
{
    for (int i = 0; i <= m; i++)
    {
        r[i] = i + 1, l[i] = i - 1;
        col[i] = u[i] = d[i]= i;
        s[i]=0;
    }
    l[0] = m, r[m] = 0;
    idx = m + 1;
}
void add(int& hh, int& tt, int x, int y)
{
    row[idx] = x, col[idx] = y, s[y]++;
    u[idx] = y, d[idx] = d[y], u[d[y]] = idx, d[y] = idx;
    r[hh] = l[tt] = idx, r[idx] = tt, l[idx] = hh;
    tt = idx++;
}
int h()
{
    int cnt = 0;
    memset(st, 0, sizeof st);
    for (int i = r[0]; i; i = r[i])
    {
        if (st[col[i]]) continue;
        cnt++;
        st[col[i]]=1;
        for (int j = d[i]; j != i; j = d[j])
            for (int c = r[j]; c != j; c = r[c])
                st[col[c]] = 1;
    }
    return cnt;
}
void remove(int p)
{
    for (int i = d[p]; i != p; i = d[i])
    {
        r[l[i]] = r[i], l[r[i]] = l[i];
    }
}
void resume(int p)
{
    for (int i = u[p]; i != p; i = u[i])
    {
        r[l[i]] = i, l[r[i]] = i;
    }
}
bool dfs(int k, int depth)
{
    if (h() + k > depth)return false;
    if (!r[0])return true;
    int p = r[0];
    for (int i = r[0]; i; i = r[i])
        if (s[i] < s[p]) p = i;

    for (int i = d[p]; i != p; i = d[i])
    {
        ans[k] = row[i];
        remove(i);
        for (int j = r[i]; j != i; j = r[j])remove(j);
        if (dfs(k + 1, depth)) return true;
        for (int j = l[i]; j != i; j = l[j])resume(j);
        resume(i);
    }
    return false;
}
int main()
{
    cin >> n >> m;
    init();
    for (int i = 1; i <= n; i++)
    {
        int hh = idx, tt = idx;
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            if (x) add(hh, tt, i, j);
        }
    }
    int depth = 0;
    while (!dfs(0, depth))depth++;
    cout << depth << endl;
    for (int i = 0; i < depth; i++) cout << ans[i] << " ";
    return 0;
}
