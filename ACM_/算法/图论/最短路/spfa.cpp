//spfa O(nm)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define x first
#define y second
using namespace std;
const int M=1500,N=810,inf=0x3f3f3f3f;
int n,p,c,cnt;
int ans=inf;
int head[N],id[N],d[N],vis[N];
struct edges
{
    int v,nxt,w;
}e[M*2];
void add(int u,int v,int w)
{
    e[cnt]={v,head[u],w},head[u]=cnt++;
    e[cnt]={u,head[v],w},head[v]=cnt++;
}
void spfa(int s)
{
    memset(d,0x3f,sizeof d);
    memset(vis,0,sizeof vis);
    queue<int>q;
    q.push(s);
    vis[s]=1;
    d[s]=0;
    while(q.size())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];~i;i=e[i].nxt)
        {
            int v=e[i].v,w=e[i].w;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                if(!vis[v])
                {
                    q.push(v);
                    vis[v]=1;
                }
            }
        }
    }
  
}
int main()
{
    memset(head,-1,sizeof head);
    cin>>n>>p>>c;
    for(int i=1;i<=n;i++) cin>>id[i];
    for(int i=0;i<c;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w);
    }
    spfa(s);
    return 0;
}

