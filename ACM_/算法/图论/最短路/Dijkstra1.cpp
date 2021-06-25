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
        for(int j=1;j<=n;j++)   //先找到最短的一个点，然后再记录这个点，对这个点到原点之间进行松弛
        {
            if(!vis[j]&&dis[j]<mind)
            mind=dis[j],p=j;
        }
        vis[p]=1;
        for(int j=1;j<=n;j++) dis[j]=min(dis[j],dis[p]+g[p][j]); //松弛
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
        g[a][b]=min(c,g[a][b]);   //判重边
    }
    dijkstra();
    if(dis[n]==inf) cout<<-1<<endl;
    else cout<<dis[n]<<endl;
    return 0;
}
