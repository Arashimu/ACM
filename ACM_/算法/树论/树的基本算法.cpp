//链式前向星 
int head[N],cnt;
struct Edge
{
	int nxt,w,v;
}e[N*2];
void add(int u,int v,int w)
{
	e[cnt].v=v,e[cnt].w=w,e[nxt]=head[u],head[u]=cnt++;
}





/*树的DFS遍历和DFS序列,其中每个节点在序列中恰好出现2次。
设这两次出现的位置为L[X],R[X]，那么闭区间[L[X],R[X]]就是以x为根的子树的DFS序 
*/ 
int m;
void dfs(int x)
{
	a[++m]=x; //a数组存储DFS序列 
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		int y=e[i].v;
		if(vis[y]) continue;
		dfs(y);
	}
	a[++m]=x; 
 } 
 
 
 
 //树的深度
 void dfs(int x)
 {
 	vis[x]=1;
 	for(int i=head[x];i;i=e[i].nxt)
 	{
 		int y=e[i].v;
 		if(vis[y]) continue;
 		d[y]=d[x]+1;
 		dfs(y);
	 }
  } 
  
  
 //树的重心
 void dfs(int x)
 {
 	vis[x]=1;size[x]=1;
 	int max_part=0;
 	for(int i=head[x];i;i=e[i].nxt)
 	{
 		int y=e[i].v;
 		if(vis[y]) continue;
 		dfs(y)
 		size[x]+=size[y];
 		max_part=max(max_part,size[y]);
	 }
	 max_part=max(max_part,n-size[x]); //n为整棵树的节点数目 
	 if(max_part<ans)
	 {
	 	ans=max_part;  //全局变量ans记录重心对应的max_part 
	 	pos=x;       //全局变量pos记录重心 
	 }
  } 
  
