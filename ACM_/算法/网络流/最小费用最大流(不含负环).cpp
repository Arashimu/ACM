//最小费用最大流，将EK算法的BFS换成SPFA，若存在负环，该模板不适用，要加入消圈发 



#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N=5005,M=50005*2,inf=1e8;
int n,m,S,T,cnt;
int head[N],d[N],st[N],pre[N],incf[N];
struct edges
{
    int v,nxt,f,c;
}e[M];
void add(int u,int v,int f,int c)
{
     e[cnt].v=v,e[cnt].nxt=head[u],e[cnt].f=f,e[cnt].c=c,head[u]=cnt++;
     e[cnt].v=u,e[cnt].nxt=head[v],e[cnt].f=0,e[cnt].c=-c,head[v]=cnt++;
}
bool spfa()
{
    memset(d,0x7f,sizeof d);
    memset(incf,0,sizeof incf);
    queue<int>q;
    q.push(S);
    d[S]=0,incf[S]=inf;
    while(q.size())
    {
        int u=q.front();
        q.pop();
        st[u]=0;
        for(int i=head[u];~i;i=e[i].nxt)
        {
            int v=e[i].v,f=e[i].f,c=e[i].c;
            if(f&&d[v]>d[u]+c)
            {
                d[v]=d[u]+c;
                pre[v]=i;
                incf[v]=min(incf[u],f);
                if(!st[v])
                {
                    st[v]=1;
                    q.push(v);
                }
                
            }
        }
    }
    return incf[T]>0;
}
void EK(int &flow,int &cost)
{
    flow=cost=0;
    while(spfa())
    {
        int t=incf[T];
        flow+=t,cost+=t*d[T];
        for(int i=T;i!=S;i=e[pre[i]^1].v)
        {
            e[pre[i]].f-=t,e[pre[i]^1].f+=t;
        }
    }
}
int main()
{
    memset(head,-1,sizeof head);
    cin>>n>>m>>S>>T;
    for(int i=1;i<=m;i++)
    {
        int u,v,f,c;
        cin>>u>>v>>f>>c;
        add(u,v,f,c);
    }
    int flow,cost;
    EK(flow,cost);
    cout<<flow<<" "<<cost<<endl;
    return 0;
}

