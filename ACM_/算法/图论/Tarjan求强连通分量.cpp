//����ͼ��ǿ��ͨ���� Tarjan
/*ǿ��ͨͼ:����һ������ͼ��������ͼ������������x,y,�ȴ��ڴ�x��y��·��,Ҳ���ڴ�y��x��·��,��Ƹ�����ͼ��"ǿ��ͨ����"
   ����ͼ�ļ���ǿ��ͨ��ͼ����Ϊ"ǿ��ͨ����",���Ϊscc.*/
//��Ȧ 

const int N=100010,M=1000010;
int n,m,cnt,timing,tot,idx;
int head[N],dfn[N],low[N];//dfnΪʱ���,low��¼��Сʱ���
int ins[N],c[N] //stack-ջ,c[x]-��¼x���ڵ�ǿ��ͨ�����ı��,ins[x]��ʾx�Ƿ���ջ�� 
vector<int> scc[N] //scc[i]��¼��i��ǿ��ͨ���������нڵ� 
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


//��Ȧ֮����c[x]��c[y] ��SCC֮������,��õ�һ�������޻�ͼ
int head_[N],cnt_; 
edges e_[M];
void add_(int u,int v)
{
	e_[u].v=v,e_[u].nxt=head_[v],head_[v]=cnt_++;
}
//mian��
for(int x=1;x<=n;x++)
{
	for(int i=head[x];~i;i=e[i].nxt)
	{
		int y=e[i].v;
		if(c[x]==c[y]) continue;
		add_(c[x],c[y]);
	}
 } 
