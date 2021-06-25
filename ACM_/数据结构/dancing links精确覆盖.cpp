#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 5550;
int n, m;
int l[N], r[N], u[N], d[N], col[N], row[N], s[N], idx; //构造的是循环十字链表
int ans[N], top;
void init()
{
    for (int i = 0; i <= m; i++)
    {
        l[i] = i - 1, r[i] = i + 1;
        u[i] = d[i] = i;
    }
    l[0] = m, r[m] = 0;
    idx = m + 1;
}
void add(int& hh, int& tt, int x, int y)   //按行插入
{
    row[idx] = x, col[idx] = y, s[y]++;
    u[idx] = y, d[idx] = d[y], u[d[y]] = idx, d[y] = idx;
    r[hh] = l[tt] = idx, r[idx] = tt, l[idx] = hh;
    tt = idx++;
}
void remove(int p)
{
    r[l[p]] = r[p], l[r[p]] = l[p];
    for (int i = d[p]; i != p; i = d[i])
        for (int j = r[i]; j != i; j = r[j])
        {
            s[col[j]]--;
            u[d[j]] = u[j], d[u[j]] = d[j];//只需要改变上下关系
        }
}
void resume(int p)
{
    for (int i = u[p]; i != p; i = u[i])
        for (int j = l[i]; j != i; j = l[j])
        {
            u[d[j]] = j, d[u[j]] = j;//只需要改变上下关系
            s[col[j]]++;
        }
    r[l[p]] = p, l[r[p]] = p;
}
bool dfs()
{
    if (!r[0]) return true;
    int p = r[0];
    for (int i = r[0]; i; i = r[i])
        if (s[i] < s[p]) p = i;

    remove(p); //剪枝 删去1的数目最少的列
    for (int i = d[p]; i != p; i = d[i])//将p列中含有1的行全部删去 从上往下搜
    {
        ans[++top] = row[i];
        for (int j = r[i]; j != i; j = r[j]) //从左往右 
            remove(col[j]);

        if (dfs()) return true;
        //回溯
        for (int j = l[i]; j != i; j = l[j])
            resume(col[j]);
        top--;
    }
    resume(p);
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
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
    if (dfs())
    {
        for (int i = 1; i <= top; i++) cout << ans[i] << " ";
        puts("");
    }
    else puts("No Solution!");
    return 0;


}


