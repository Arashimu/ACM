
//最大流EK算法 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
const int N=202,M=5005,INf=0x7f7f7f7f;
int n,m,idx,S,T;
int head[N],pre[N],vis[N];
ll d[N];
struct edges
{
	int v,nxt;
	ll f;
}e[M*2];  //要建反向图，边数*2 
void add(int u,int v,ll c )
{
	e[idx].v=v,e[idx].nxt=head[u],e[idx].f=c,head[u]=idx++;
	e[idx].v=u,e[idx].nxt=head[v],e[idx].f=0,head[v]=idx++;
}
bool bfs()    //找增广路 
{
	queue<int>q;
	memset(vis,0,sizeof vis);
	q.push(S);
	vis[S]=1,d[S]=INf;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];~i;i=e[i].nxt)
		{
			int v=e[i].v;
			ll f=e[i].f;
			if(!vis[v]&&f)
			{
				vis[v]=1;
				pre[v]=i;       //记录上一条边,便于构建残留网络 
				d[v]=min(d[u],f);  //遵守流量限制 
				if(v==T) return true;
				q.push(v);
			}
		}
	}
	return false;
}
ll EK()
{
	ll res=0;
    while(bfs())
    {
    	res+=d[T];
    	for(int i=T;i!=S;i=e[pre[i]^1].v)   
         e[pre[i]].f-=d[T],e[pre[i]^1].f+=d[T];
	}

    return res;
}
int main()
{
	memset(head,-1,sizeof head);
	cin>>n>>m>>S>>T;
	for(int i=1;i<=m;i++)
	{
		int u,v; ll c;
		cin>>u>>v>>c;
		add(u,v,c);
	}
	cout<<EK()<<endl;
	return 0;
}
