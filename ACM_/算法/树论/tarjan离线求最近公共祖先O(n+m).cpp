#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N=1e4+10,M=N*2;
typedef pair<int,int>pii;
int n,m,cnt;
int head[N],st[N],f[N],d[N],res[M];
vector<pii> q[N];
struct edges
{
    int v,nxt,w;
}e[M];
void add(int u,int v,int w)
{
    e[cnt]={v,head[u],w},head[u]=cnt++;
}
int find(int x)
{
    return f[x]==x?x:find(f[x]);
}
void dfs(int u,int fa)
{
    for(int i=head[u];~i;i=e[i].nxt)
    {
        int v=e[i].v,w=e[i].w;
        if(v!=fa)
        {
            d[v]=d[u]+w;
            dfs(v,u);
        }
    }
}
void tarjan(int u)
{
    st[u]=1;
    for(int i=head[u];~i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(!st[v])
        {
            tarjan(v);
            f[v]=u;
        }
    }
    for(auto i:q[u])
    {
        int y=i.first,id=i.second;
        if(st[y]==2)
        {
            int anc=find(y);
            res[id]=d[y]+d[u]-2*d[anc];
        }
    }
    st[u]=2;
}
int main()
{
    cin>>n>>m;
    memset(head,-1,sizeof head);
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<n;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w),add(v,u,w);
    }
    dfs(1,-1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u!=v)
        {
            q[u].push_back({v,i});
            q[v].push_back({u,i});
        }
    }
    tarjan(1);
    for(int i=1;i<=m;i++) cout<<res[i]<<endl;
    return 0;
}
