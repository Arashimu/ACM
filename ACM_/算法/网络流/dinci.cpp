#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N,M,INF;
int n,m,S,T,cnt;
int head[N],d[N],cur[N];
struct edges
{
	int v,nxt,f;
}e[M*2];
void add(int u,int v,int f)
{
	e[cnt].v=v,e[cnt].nxt=head[u],e[cnt].f=f,head[u]=cnt++;
	e[cnt].v=u,e[cnt].nxt=head[v],e[cnt].f=0,head[v]=cnt++;
}

bool bfs()
{
	memset(d,-1,sizeof d);
	queue<int>q;
	q.push(S);
	d[S]=0,cur[S]=head[S];
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=head[u];~i;i=e[i].nxt)
		{
			int v=e[i].v,f=e[i].f;
			if(d[v]==-1&&f)
			{
				d[v]=d[u]+1;
				cur[v]=head[v];
				if(v==T) return true;
				q.push(v);
			}
		}
	}
	return false;
}
int find(int u,int limit)
{
	if(u==T) return limit;
	int flow=0;
	for(int i=cur[u];~i&&flow<limit;i=e[i].nxt)
	{
		cur[u]=i;
		int v=e[i].v,f=e[i].f;
		if(d[v]==d[u]+1&&f)
		{
			int t=find(v,min(f,limit-flow));
			if(!t) d[v]=-1;
			e[i].f-=t,e[i^1].f+=t,flow+=t;
		}
	}
	return flow;
}
int dinic()
{
	int ans=0,flow;
	while(bfs()) while(flow=find(S,INF)) ans+=flow;
	return ans;
}

int main()
{
    memset(head,-1,sizeof head);
    cin>>n>>m>>S>>T;
	for(int i=1;i<=m;i++)
	{
		int u,v,f;
		cin>>u>>v>>f;
		add(u,v,f);
    }
	cout<<dinic()<<endl;
	return 0;	
}
