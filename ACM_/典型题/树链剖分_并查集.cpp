
/*题目:你手里有K条边还没有分配权值,已经存在M条边带权值,如何给你手中的边分配权值,使得K条边都在最后的最小生成树中且最后权值和最大.
4 3 6
1 2
3 4
1 3
2 3 3
3 1 4
1 2 4
4 2 8
4 3 8
4 1 10

14
*/

/*
思路一:树链剖分+线段树维护最小值 
1.考虑令k条无权边权值为0，建出最小生成树。

2.将最小生成树中的无权边权值设为INF，有权边权值设为0，将最小生成树树链剖分

3.然后对于每一条没有包含在最小生成树中的带权边(u,v,d)，我们需要让最小生成树上(u,v)这条路径上的所有边权值对d取min

4.答案就是最小生成树的权值和
*/
 
#include <algorithm>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
const int N=1110000,inf=1e15;
int n,k,m,cnt,idx,tot;
int f[N],head[N],ans[N];
int dep[N],sz[N],fa[N],son[N],d[N];
int id[N],top[N],pre[N];
struct edges
{
	int v,nxt,w;
 }e[N];
 struct Segment_tree
 {
     int flag,maxn;	
 }t[N*4];
 struct node
 {
 	int x,y,w,flag;
 }p[N];
 void add(int u,int v,int w)
 {
 	e[cnt]={v,head[u],w},head[u]=cnt++;
 	e[cnt]={u,head[v],w},head[v]=cnt++;
 }
 int find(int x)
 {
 	return x==f[x]?x:f[x]=find(f[x]);
 }
 void dfs1(int u,int father,int depth)
 {
 	dep[u]=depth,fa[u]=father,sz[u]=1;
 	for(int i=head[u];~i;i=e[i].nxt)
 	{
 		int v=e[i].v;
 		if(v==father) continue;
 		d[v]=e[i].w;
 		dfs1(v,u,depth+1);
 		sz[u]+=sz[v];
 		if(sz[son[u]]<sz[v]) son[u]=v;
 	 }
 }
 void dfs2(int u,int t)
 {
 	id[u]=++idx,top[u]=t,pre[idx]=u;
 	if(son[u]) dfs2(son[u],t);
 	for(int i=head[u];~i;i=e[i].nxt)
 	{
 		int v=e[i].v;
 		if(v==son[u]||v==fa[u]) continue;
 		dfs2(v,v);
	 }
 }
 void pushup(int root)
 {
 	t[root].maxn=max(t[root<<1].maxn,t[root<<1|1].maxn);
 	return;
 }
void pushdown(int root)
{
	if(!t[root].flag )return;
	if(t[root].flag<=t[root<<1].maxn)
	{
		t[root<<1].maxn=t[root].flag,t[root<<1].flag=t[root].flag;
	}
	if(t[root].flag<=t[root<<1|1].maxn )
	{
		t[root<<1|1].maxn=t[root].flag,t[root<<1|1].flag=t[root].flag;
	}
	t[root].flag =0;
 } 
 void build(int root,int l,int r)
 {  
 	if(l==r)
 	{
 		t[root].maxn=d[pre[l]];

 		return ;
	 }
	 int mid=l+r>>1;
	 build(root<<1,l,mid);
	 build(root<<1|1,mid+1,r);
	 pushup(root);
 }
 void update(int root,int l,int r,int xl,int xr,int d)
 {
 	
 	if(d>t[root].maxn)return;
 	if(l==xl&&r==xr)
 	{
 		t[root].maxn=d;
 		t[root].flag=d;
 		return;
	 }
	 pushdown(root);
	 int mid=l+r>>1;
	 if(xr<=mid)update(root*2,l,mid,xl,xr,d);
	else
		if(xl>mid)update(root*2+1,mid+1,r,xl,xr,d);
		else	
		{
			update(root*2,l,mid,xl,mid,d);
			update(root*2+1,mid+1,r,mid+1,xr,d);
		}
	 pushup(root);
 }

 void update_path(int u,int v,int d)
 {
 	while(top[u]!=top[v])
 	{
 		if(dep[top[u]]<dep[top[v]]) swap(u,v);
 		update(1,1,n,id[top[u]],id[u],d);
 		u=fa[top[u]];
 	 }
 	 if(u==v)return;
 	 if(dep[u]<dep[v]) swap(u,v);
 	 update(1,1,n,id[v]+1,id[u],d);
 }
 int lca(int u,int v)
 {
       while(top[u]!=top[v])
       {
       	  if(dep[top[u]]<dep[top[v]])swap(u,v);
       	  u=fa[top[u]];
 	   }
 	   if(dep[u]<dep[v]) return u;
 	   else return v;
 }
 void query(int root,int l,int r)
 {
 	if(l==r)
 	{
 		ans[pre[l]]=t[root].maxn;
 		return;
	 }
	 pushdown(root);
	 int mid=l+r>>1;
	query(root<<1,l,mid);
	 query(root<<1|1,mid+1,r);
 }
 signed main()
 {
 	scanf("%lld%lld%lld",&n,&k,&m);
 	memset(head,-1,sizeof head);
 	for(int i=1;i<=n;i++) f[i]=i;
 	for(int i=1;i<=k;i++)
 	{
 		int x,y;
 		scanf("%lld%lld",&x,&y);
 		if(find(x)!=find(y))
 		{
 			f[find(x)]=find(y);
 			add(x,y,inf);
 			tot++;
		 }
	 }
	 for(int i=1;i<=m;i++)
	 {
	 	scanf("%lld%lld%lld",&p[i].x,&p[i].y,&p[i].w);
	 	if(find(p[i].x)!=find(p[i].y))
	 	{
	 		f[find(p[i].x)]=find(p[i].y);
	 		add(p[i].x,p[i].y,0);
	 		p[i].flag=1;
	 		tot++;
		 }
	 }
	 dfs1(1,1,1);
	 dfs2(1,1);
	 build(1,1,n);
	 for(int i=1;i<=m;i++)
	 {
	 	if(!p[i].flag)
	 	{
	 		int t=lca(p[i].x,p[i].y);
	 		update_path(p[i].x,t,p[i].w);
	 		update_path(p[i].y,t,p[i].w);
		 }
	 }
	 query(1,1,n);
	 for(int i=1;i<=n;i++)
	 if(ans[i]==inf)
	 {
	 	printf("-1");
	 	return 0;
	 }
	 else ans[i]+=ans[i-1];
	 
	 printf("%lld",ans[n]);
 }
 
 
 /*
思路二:
排序+并查集
kruskal倒是挺好想的，如果要是能快速求到总图中两点间所有路径中最小边权值，那很好做。但是这东西并不好求
换一种思路，既然原图一定为最小生成树，不妨先以原图建一棵最小生成树，不够的边用有边权的边补上。
剩下的有边权的边，就是限制条件了。每有一条(x,y,c)的边，意思是x-y路径上的最大边权为c，所以我们可以用一些维护树链的数据结构类做

可以把所有新路递增排序，所以前面更新过的路后面一定不会再更新。
暴力的话就是把(x,lca)和(y,lca)的路径全部走一遍。=>一种巧妙的方法是用并查集做路径压缩。
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5e5+10;
 
int n,K,m;
 
int fa[MAXN];
int findfa(int x){return x==fa[x]?fa[x]:fa[x]=findfa(fa[x]);}
 
struct E{int x,y,c,next;}e[MAXN*2],a[MAXN];int len=1,tot=0,last[MAXN];
void ins(int x,int y,int c)
{
    e[++len]=(E){x,y,c,last[x]};last[x]=len;
}
 
int F[MAXN],dep[MAXN],edge[MAXN];
void dfs(int x)
{
    for(int k=last[x];k;k=e[k].next)
    {
        int y=e[k].y;
        if(y==F[x]) continue;F[y]=x;
        dep[y]=dep[x]+1;
        edge[y]=k;
        dfs(y);
    }
}
 
int main()
{
    scanf("%d %d %d",&n,&K,&m);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=K;i++)
    {
        int x,y;scanf("%d %d",&x,&y);
        ins(x,y,0);ins(y,x,0);
        fa[findfa(x)]=findfa(y);
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,c;scanf("%d %d %d",&x,&y,&c);
        if(findfa(x)!=findfa(y))
        {
            ins(x,y,c);ins(y,x,c);
            fa[findfa(x)]=findfa(y);
        }
        else a[++tot]=(E){x,y,c};
    }
    dep[1]=1;dfs(1);
    
    ll ans=0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=tot;i++)
    {
        int x=findfa(a[i].x),y=findfa(a[i].y),c=a[i].c;
        while(x!=y)
        {
            if(dep[x]<dep[y]) swap(x,y);
            if(!e[edge[x]].c) ans+=a[i].c,K--;
            fa[x]=F[x];x=findfa(x);
        }
    }
    if(K) puts("-1");
    else printf("%lld\n",ans);
    return 0;
} 
