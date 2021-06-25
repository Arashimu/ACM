//有向图的强联通分量 Tarjan
/*强联通图:给定一张有向图。若对于图中任意两个点x,y,既存在从x到y的路径,也存在从y到x的路径,则称该有向图是"强联通分量"
   有向图的极大强连通子图被称为"强联通分量",简记为scc.*/
//缩圈 

const int N=100010,M=1000010;
int n,m,cnt,timing,tot,idx;
int head[N],dfn[N],low[N];//dfn为时间戳,low记录最小时间戳
int ins[N],c[N] //stack-栈,c[x]-记录x所在的强连通分量的编号,ins[x]表示x是否在栈中 
vector<int> scc[N] //scc[i]记录了i号强连通分量的所有节点 
stack<int>s;
struct edges
{
	int v,nxt;
}e[M];
void add(int u,int v)
{
	e[cnt].v=v,e[cnt].nxt=head[u],head[u]=cnt++;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++timing;
	s.push(x),ins[x]=1;
	for(int i=head[x];~i;i=e[i].nxt)
	{
		int y=e[i].v;
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(ins[y]) low[x]=min(low[x],dfn[y]);
		if(dfn[x]==low[x])
		{
			idx++;int top;
			do
			{
				top=s.top();
				s.pop();
				ins[top]=0;
				c[top]=idx,scc[idx].push_back(top);
			}while(x!=top);
		}
	}
	
}


//缩圈之后在c[x]与c[y] 的SCC之间连边,会得到一张有向无环图
int head_[N],cnt_; 
edges e_[M];
void add_(int u,int v)
{
	e_[u].v=v,e_[u].nxt=head_[v],head_[v]=cnt_++;
}
//mian中
for(int x=1;x<=n;x++)
{
	for(int i=head[x];~i;i=e[i].nxt)
	{
		int y=e[i].v;
		if(c[x]==c[y]) continue;
		add_(c[x],c[y]);
	}
 } 
