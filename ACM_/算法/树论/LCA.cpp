void bfs()
{
    memset(d,0x3f,sizeof d);
    d[0]=0,d[root]=1;
    queue<int>q;
    q.push(root);
    while(q.size())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];~i;i=e[i].nxt)
        {
            int v=e[i].v;
            if(d[v]>d[u]+1)
            {
                d[v]=d[u]+1;
                q.push(v);
                f[v][0]=u;
                for(int k=1;k<=15;k++)
                f[v][k]=f[f[v][k-1]][k-1];
            }
        }
    }
}
int lca(int a,int b)
{
    if(d[a]<d[b])swap(a,b);
    for(int k=15;k>=0;k--)
    if(d[f[a][k]]>=d[b]) a=f[a][k];
    if(a==b) return a;
    for(int k=15;k>=0;k--)
    if(f[a][k]!=f[b][k])
    {
        a=f[a][k];
        b=f[b][k];
    }
    return f[a][0];
}

