//最小生成树

//Kruskal
struct rec
{
	int x,y,z;
 }edge[N] ;
 int fa[N],n,m,ans;
 
 bool cmp(rec a,rec b)
 {
 	if(a.z<b.z) return true;
 	else return false;
 }
 
 /*
 bool operator < (rec a,rec b)
 {
   return a.z<b.z;
}
*/

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	cin>>edge[i].x>>edge[i].y>>edge[i].z;
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=find(edge[i].x);
		int y=find(edge[i].y);
		if(x==y) continue;
		fa[x]=y;
		ans+=edge[i].z;
	}
}


//Prinm
void prim()
{
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	d[1]=0;
	for(int i=1;i<=n;i++)
	{
		int x=0;
		for(int j=1;j<=n;j++)
		{
			if(!vis[x]&&(x==0)||d[j]<d[x]) x=j;
		}
		vis[x]=1;
		for(int y=1;y<=n;y++)
		if(!vis[y]) d[y]=min(d[y],a[x][y]);
	}
}
 
