//树的直径与最近公共祖先



//树的直径   可以求带负权的树 
void dp(int x)
{
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		int y=e[i].v;
		if(vis[y]) continue;
		dp(y);
		ans=max(ans,d[x]+d[y]+e[i].w);
		d[x]=max(d[x],d[y]+e[i].w);
	}
}

//最近公共祖先lca
int t;
void bfs()
{
	q.push(1);
	d[1]=1;
	while(q.size())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt)
		{
			int y=e[i].v;
			if(d[y]) continue;
			d[y]=d[x]+1;
			dist[y]=dist[x]+e[i].w;
			f[y][0]=x;
			for(int j=1;j<=t;j++)
			f[y][j]=f[f[y][j-1]][j-1];
			q.push(y);
		}
	}
}

int lca(int x,int y)
{
	if(d[x]>d[y]) swap(x,y);
	for(int i=t;i>=0;i--)
		if(d[f[y][i]]>=d[x]]) y=f[y][i];
	if(x==y) return x;
	for(int i=t;i>=0;i--)
	 if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	 return f[x][0];
}
int main()
{
	cin>>n>>m;
	t=(int)(log(n)/log(2))+1;
	for(int i=1;i<=n;i++) head[i]=d[i]=0;
	tot=0;
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z),add(y,x,z);
	}
	bfs();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<dist[x]+dist[y]-2*dist[lca(x,y)];
	}
 } 

//lca的Tarjan算法 
