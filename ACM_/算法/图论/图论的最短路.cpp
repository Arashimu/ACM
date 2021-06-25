//图论算法

int head[N],cnt;
struct edges
{
	int nxt,v,w;
}e[N*2];
void add(int u,int v,int w)
{
	e[++cnt].v=v,e[cnt].nxt=head[u],e[cnt].w=w,head[u]=cnt;
}


//Dijkstra
int vis[N],d[N];
void dijkstra()
{
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	d[1]=0;
	for(int i=1;i<n;i++)
	{
		int x=0;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&(x==0||d[j]<d[x]))
			x=j;
		}
		vis[x]=1;
		for(int y=1;y<=n;y++)
		d[y]=min(d[y],d[y]+a[x][y]);
	}
 } 
 
 
 //priority_queue 优化dijkstra
 priority_queue<pair<int,int>>q;
 void dijkstra()
 {
 	memset(d,0x3f,sizeof d);
 	memset(vis,0,sizeof vis);
 	d[1]=0;
 	q.push(make_pair(0,1));
 	while(q.size())
 	{
 		int x=q.front().second;
		 q.pop();
		 if(vis[x]) continue;
		 v[x]=1;
		 for(int i=head[x];i;i=e[i].nxt)
		 {
		 	int y=e[i].v;
		 	int w=e[i].w;
		 	if(d[y]>d[x]+w)
		 	{
		 		d[y]=d[x]+w;
		 		q.psuh(make_pair(-d[y],y));
			 }
		 }
	 }
 }
  
  
//SPFA 可以判断负换
int in[N]  //判断负环的数组 
void spfa()
{
	queue<int>q;
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	d[1]=0; vis[1]=1;
	q.push(1);
	in[1]++;
	while(q.size())
	{
		int x=q.front(); q.pop();
		if(in[x]>n) return 1 //存在负环 
		vis[x]=0;
		for(int i=head[x];i;i=e[i].nxt)
		{
			int y=e[i].v;
			int w=e[i].w;
			if(d[y]>d[x]+w)
			{
				d[y]=d[x]+w;
				if(!vis[y]) q.push(y),vis[y]=1;
			}
		}
	}
 }
 
 
 
 //floyd
 int d[N][N];
 void floyd()
 {
 	for(int k=1;k<=n;;k++)
 	  for(int i=1;i<=n;i++)
 	    for(int j=1;j<=n;j++)
	        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  }
  
  
   
