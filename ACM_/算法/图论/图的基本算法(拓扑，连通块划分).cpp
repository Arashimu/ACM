//��ʽǰ���� 
int head[N],cnt;
struct Edge
{
	int nxt,w,v;
}e[N*2];
void add(int u,int v,int w)
{
	e[cnt].v=v,e[cnt].w=w,e[nxt]=head[u],head[u]=cnt++;
}



//ͼ����ͨ�黮��
int cnt=0;
void dfs(int x)
{
	vis[x]=cnt;
	for(int i=head[x];i;i=e[i].nxt)
	{
		int y=e[i].v;
		if(vis[y]) continue;
		dfs(y);
	}
}
for(int i=1;i<=n;i++)
{
	if(!v[i])
	{
		cnt++;
		dfs(i);
	}
}


//ͼ��bfs
#include <queue>
void bfs()
{
	memset(d,0,sizeof d);
	queue<int>q;
	q.push(1);d[1]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=e[i].nxt)
		{
			int y=e[i].v;
			if(d[y]) continue;
			d[y]=d[x]+1;
			q.push(y);
		}
	}
 }
 
 
 //ͼ���������� 
 //��ʽǰ����  ����ͼ 
int head[N],cnt,c,deg[N];
struct Edge
{
	int nxt,w,v;
}e[N*2];
void add(int u,int v,int w)
{
	e[cnt].v=v,e[cnt].w=w,e[nxt]=head[u],head[u]=cnt++,deg[v]++;
}
void topsort()
{
	queue<int>q;
	for(int i=1;i<=n;i++)
	if(deg[i]==0) q.push(i);
	while(q.size())
	{
		int x=q.front();
		q.pop();
		a[++c]=x;   //a�����¼���������� 
		for(int i=head[x];i;i=e[i].nxt)
		{
			int y=e[i].v;
			if(--deg[y]==0) q.push(y);
		}
	}
}
