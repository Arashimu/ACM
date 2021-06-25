//O(n^3)
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=110,inf=0x3f3f3f3f;
int g[N][N];
int n,m;
int f[N][N];
int main()
{
    cin>>n>>m;
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=m;i++)
    {
        int u,v,k;
        cin>>u>>v>>k;
        g[u][v]=g[v][u]=min(g[u][v],k);
    }
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
    
    int minn=0;
    for(int i=2;i<=n;i++)
     if(g[1][i]==inf) 
     {
         puts("-1");
         return 0;
     }
     else minn=max(minn,g[1][i]);
     cout<<minn<<endl;
     return 0;
}
