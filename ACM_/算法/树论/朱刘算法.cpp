//朱刘算法：求有向图的最小生成树
#include <iostream>
#include <algorihtm>
#include <cstring>
#include <stack>
using namespace std;
const int N,M,inf;
int n,m;
int g[N][N],st[N];
int timing,tot,ins[N],dfn[N],low[N],id[N];
int pre[N],d[N],bd[N];
int f[N];
struct edges
{
	int v,nxt;
}e[M];

void dfs(int u)
{
	st[u]=1;
	for(int i=head[u];~i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(d[u][v]&&!st[v]) dfs(v);
	}
}
bool check()
{
	bfs(1);
	for(int i=1;i<=n;i++)
	if(!st[i]) return false;
	return true;
 }
void tarjan(int u)
{
	dfn[u]=low[u]=++timing;
	s.push(u),ins[u]=1;
	int v=pre[u];
	if(!dfn[v])
	{
		tarjan(v);
		low[u]=min(low[v],low[u]);
	}
	else if(insv) low[u]=min(dfn[v],low[u]);
	if(low[u]==dfn[u])
	{
		int top;
		tot++;
		do
		{
			top=s.top();
			s.pop();
			ins[top]=0;
			id[top]=tot;
		}while(top!=u);
	}
	
}
int ZL_work()
{
	int ans=0;
	while(1)
	{
	
	for(int i=1;i<=n;i++)
	{
		pre[i]=i;
		for(int j=1;j<=n;j++)
		if(d[j][i]<d[pre[i]][i]) pre[i]=j;
	}
	
	
	memset(dfn,0,sizeof dfn);
	timing=tot=0;
		for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
		if(tot==n)
		{
			for(int i=2;i<=n;i++)
			ans+=d[pre[i]][i];
			break;
		}
		for(int i=1;i<=tot;i++)
		for(int j=1;j<=tot;j++)
		bd[i][j]=inf;
		
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		if(d[i][j]<0x3f3f3f3f&&id[i]!=id[j])
		{
			int a=id[i],b=id[j];
			if(id[pre[j]]==id[j]) bd[a][b]=min(bd[a][b],d[i][j]-d[pre[j]][j]);
			else bd[a][b]=mib(bd[a][b],d[i][j]);
		}
		n=tot;
		memcpy(d,bd,sizeof d);
		
	}
	return ans;
}

int mian()
{
     scanf("%d%d",&n,&m);
	 memset(d,0x3f,sizeof d);
	 for(int i1;i<=m;i++)
	 {
	 	int u,v,c;
	 	scanf("%d%d%d",&u,&v,&c);
	 	d[u][v]=c;
	 	f[v]=u;
	}
	if(!check()) printf("NO\n");
	else printf("%d\n",ZL_work());
	return 0;	
}
