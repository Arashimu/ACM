#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N=505,inf=0x3f3f3f3f;
int dis[N],g[N][N],vis[N];
int n,m;

void dijkstra()
{
    memset(vis,0,sizeof vis);
    dis[1]=0;
    for(int i=1;i<=m;i++)
    {
        int p,mind=inf;
        for(int j=1;j<=n;j++)   //���ҵ���̵�һ���㣬Ȼ���ټ�¼����㣬������㵽ԭ��֮������ɳ�
        {
            if(!vis[j]&&dis[j]<mind)
            mind=dis[j],p=j;
        }
        vis[p]=1;
        for(int j=1;j<=n;j++) dis[j]=min(dis[j],dis[p]+g[p][j]); //�ɳ�
    }
}
int main()
{
    memset(dis,inf,sizeof dis);
    memset(g,inf,sizeof g);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a][b]=min(c,g[a][b]);   //���ر�
    }
    dijkstra();
    if(dis[n]==inf) cout<<-1<<endl;
    else cout<<dis[n]<<endl;
    return 0;
}
