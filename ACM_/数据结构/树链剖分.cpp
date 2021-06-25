//Ê÷Á´ÆÊ·Ö+Ïß¶ÎÊ÷ 
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
const int N=1e5+5,M=N*2;
int n,T,cnt,idx,w[N];
int head[N],fa[N],sz[N],dep[N],son[N];
int id[N],nw[N],top[N];
struct edges
{
   int v,nxt;
}e[M];
struct Segment_tree
{
    int l,r;
    ll sum,add;
}t[M*4];
void add(int u,int v)
{
    e[cnt]={v,head[u]},head[u]=cnt++;
    e[cnt]={u,head[v]},head[v]=cnt++;
}
void dfs1(int u,int father,int depth)
{
    fa[u]=father,dep[u]=depth,sz[u]=1;
    for(int i=head[u];~i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==father) continue;
        dfs1(v,u,depth+1);
        sz[u]+=sz[v];
        if(sz[son[u]]<sz[v]) son[u]=v;
    }
}
void dfs2(int u,int f)
{
    id[u]=++idx,nw[id[u]]=w[u],top[u]=f;
    if(!son[u]) return;
    dfs2(son[u],f);
    for(int i=head[u];~i;i=e[i].nxt)
    {
        int v=e[i].v;
        if(v==son[u]||v==fa[u]) continue;
        dfs2(v,v);
    }
}
void pushup(int u)
{
    t[u].sum=t[u<<1].sum+t[u<<1|1].sum;
}
void pushdown(int u)
{
    auto &root=t[u],&left=t[u<<1],&right=t[ u<<1 | 1];
    if(root.add)
    {
        left.add+=root.add,left.sum+=root.add*(left.r-left.l+1);
        right.add+=root.add,right.sum+=root.add*(right.r-right.l+1);
        root.add=0;
    }
}

void build(int root,int l,int r)
{
    t[root]={l,r,nw[r],0};
    if(l==r)return ;
    int  mid=l+r>>1;
    build(root<<1,l,mid);
    build(root<<1|1,mid+1,r);
    pushup(root);
}
void update(int root,int l,int r,int v)
{
    if(l<=t[root].l&&t[root].r<=r)
    {
        t[root].add+=v;
        t[root].sum+=v*(t[root].r-t[root].l+1);
        return ;
    }
    pushdown(root);
    int mid=t[root].l+t[root].r>>1;
    if(l<=mid) update(root<<1,l,r,v);
    if(r>mid) update(root<<1|1,l,r,v);
    pushup(root);
}
ll query(int root,int l,int r)
{
    ll res=0;
    if(l<=t[root].l&&t[root].r<=r)
        return t[root].sum;
    pushdown(root);
    int  mid=t[root].l+t[root].r>>1;
    if(l<=mid) res+=query(root<<1,l,r);
    if(r>mid) res+=query(root<<1|1,l,r);
    return res;
}
void update_path(int u,int v,int k)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        update(1,id[top[u]],id[u],k);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    update(1,id[v],id[u],k);
}
void update_tree(int u,int k)
{
    update(1,id[u],id[u]+sz[u]-1,k);
}
ll query_path(int u,int v)
{
    ll res=0;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res+=query(1,id[top[u]],id[u]);
        u=fa[top[u]];
    }
    if(dep[u]<dep[v])swap(u,v);
    res+=query(1,id[v],id[u]);
    return res;
}
ll query_tree(int u)
{
    query(1,id[u],id[u]+sz[u]-1);
}
int main()
{
    memset(head,-1,sizeof head);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
    }
    dfs1(1,-1,1);
    dfs2(1,1);
    build(1,1,n);
    cin>>T;
    while(T--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int u,v,k;
            cin>>u>>v>>k;
            update_path(u,v,k);
        }
        else if(op==2)
        {
            int u,k;
            cin>>u>>k;
            update_tree(u,k);
        }
        else if(op==3)
        {
            int u,v;
            cin>>u>>v;
            cout<<query_path(u,v)<<endl;
        }
        else 
        {
            int u;
            cin>>u;
            cout<<query_tree(u)<<endl;
        }
    }
    return 0;
}
