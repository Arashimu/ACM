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





/*����DFS������DFS����,����ÿ���ڵ���������ǡ�ó���2�Ρ�
�������γ��ֵ�λ��ΪL[X],R[X]����ô������[L[X],R[X]]������xΪ����������DFS�� 
*/ 
int m;
void dfs(int x)
{
	a[++m]=x; //a����洢DFS���� 
	vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		int y=e[i].v;
		if(vis[y]) continue;
		dfs(y);
	}
	a[++m]=x; 
 } 
 
 
 
 //�������
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
  
  
 //��������
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
	 max_part=max(max_part,n-size[x]); //nΪ�������Ľڵ���Ŀ 
	 if(max_part<ans)
	 {
	 	ans=max_part;  //ȫ�ֱ���ans��¼���Ķ�Ӧ��max_part 
	 	pos=x;       //ȫ�ֱ���pos��¼���� 
	 }
  } 
  
