//O(mlogn)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
#define x first
#define y second
using namespace std;

const int N=150005,inf=0x3f3f3f3f;

typedef pair<int,int>PII;

int n,m,cnt=1,dis[N],vis[N];
int head[N];

struct edge
{
    int v,nxt,w;
}e[N];

void add(int u,int v,int w)
{
    e[cnt].v=v,e[cnt].w=w,e[cnt].nxt=head[u],head[u]=cnt++;
}

void dijkstra_priority()
{
    priority_queue<PII>q;
    dis[1]=0;
    q.push({dis[1],1});
    while(q.size())
    {
        
        int u=q.top().y;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].v;
            int w=e[i].w;
            if(!vis[v]&&dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.push({-dis[v],v});
            }
        }
    }
    return;
}
int main()
{
    memset(dis,inf,sizeof dis);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    dijkstra_priority();
    if(dis[n]==inf) cout<<"-1"<<endl;
    else cout<<dis[n]<<endl;
    return 0;
}

