#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int N = 2e6 + 5;
char s[N];
int head[N];
int cnt = 0, tot = 1, last = 1;
ll f[N], ans;
struct edges
{
    int v, nxt;
}e[N];
struct Node
{
    int len, fa;
    int ch[26];
}node[N];

void add(int u, int v)
{
    e[cnt] = { v,head[u] }, head[u] = cnt++;
}
void extend(int c)
{
    int p = last, np = last = ++tot;
    f[tot] = 1;
    node[np].len = node[p].len + 1;
    for (; p && !node[p].ch[c]; p = node[p].fa) node[p].ch[c] = np;
    if (!p) node[np].fa = 1;
    else
    {
        int q = node[p].ch[c];
        if (node[q].len == node[p].len + 1) node[np].fa = q;
        else
        {
            int nq = ++tot;
            node[nq] = node[q], node[nq].len = node[p].len + 1;
            node[q].fa = node[np].fa = nq;
            for (; p && node[p].ch[c] == q; p = node[p].fa) node[p].ch[c] = nq;
        }
    }
}
void dfs(int u)
{
    for (int i = head[u]; ~i; i = e[i].nxt)
    {
        dfs(e[i].v);
        f[u] += f[e[i].v];
    }
    if (f[u] > 1) ans = max(ans, f[u] * node[u].len);
}
int main()
{
    scanf("%s", s);
    for (int i = 0; s[i]; i++)extend(s[i] - 'a');
    memset(head, -1, sizeof head);
    for (int i = 2; i <= tot; i++) add(node[i].fa, i);
    dfs(1);
    cout << ans << endl;
    return 0;
}
/*
struct state {
  int len, link;
  int next[26];
}; 
const int MAXLEN = 100000;
state st[MAXLEN * 2];
int sz, last;
void sam_extend(char c) {
  int cur = sz++;
  st[cur].len = st[last].len + 1;
  int p = last;
  while (p != -1 && !st[p].next[c]) {
    st[p].next[c] = cur;
    p = st[p].link;
  }
  if (p == -1) {
    st[cur].link = 0;
  } else {
    int q = st[p].next[c];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = sz++;
      st[clone] = st[q];
      st[clone].len = st[p].len + 1;
      while (p != -1 && st[p].next[c] == q) {
        st[p].next[c] = clone;
        p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}
