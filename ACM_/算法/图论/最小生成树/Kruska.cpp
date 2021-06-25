#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=105;
int g[N][N],f[N];
int n,m;
struct edges
{
    int u,v,w;
    bool operator < (const edges &t) const
    {
        return w<t.w;
    }
}e[N*N];
int find(int x)
{
    return f[x]==x?x:find(f[x]);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        int x;
        cin>>x;
        if(i==j) continue;
        else
        {
            e[m++]={i,j,x};
        }
    }
    sort(e,e+m);
    int ans=0;
    for(int i=0;i<m;i++)
    {
        int x=e[i].u,y=e[i].v;
        int fx=find(x),fy=find(y);
        if(fx!=fy)
        {
            ans+=e[i].w;
            f[fx]=fy;
        }
    }
    cout<<ans<<endl;
    return 0;
}
