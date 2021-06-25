/*动态树:
 支持断开x到 y的边,也支持连接x和y,
 分为虚边和实边，实边用splay维护
 */ 

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1e5+10;
int n,m;
struct lc_tree
{
      int s[2],p,v;
      int sum,rev;
}t[N];
int stk[N];
void pushrev(int x)
{

    swap(t[x].s[0],t[x].s[1]);
    t[x].rev^=1;
}
void pushup(int x)
{
    t[x].sum=t[t[x].s[0]].sum^t[x].v^t[t[x].s[1]].sum;
}
void pushdown(int x)
{
    if(t[x].rev)
    {
        pushrev(t[x].s[0]),pushrev(t[x].s[1]);
        t[x].rev=0;
    }
}
bool isroot(int x)
{
    return t[t[x].p].s[0]!=x&&t[t[x].p].s[1]!=x;
}
void rotate(int x)
{
    int y=t[x].p,z=t[y].p;
    int k=t[y].s[1]==x;
    if(!isroot(y))t[z].s[t[z].s[1]==y]=x;
    t[x].p=z;
    t[y].s[k]=t[x].s[k^1],t[t[x].s[k^1]].p=y;
    t[x].s[k^1]=y,t[y].p=x;
    pushup(y),pushup(x);
}
void splay(int x)
{
    int top=0,r=x;
    stk[++top]=r;
    while(!isroot(r)) stk[++top]=r=t[r].p;
    while(top) pushdown(stk[top--]);
    while(!isroot(x))
    {
        int y=t[x].p,z=t[y].p;
        if(!isroot(y))
        if((t[z].s[1]==y)^(t[y].s[1]==x)) rotate(x);
        else rotate(y);
        rotate(x);
    }
}
void access(int x)//// 建立一条从根到x的路径，同时将x变成splay的根节点
{
    int z=x;
    for(int y=0;x;y=x,x=t[x].p)
    {
        splay(x);
        t[x].s[1]=y,pushup(x);//后继
    }
    splay(z);
}
void makeroot(int x)
{
    access(x);
    pushrev(x);
}
int findroot(int x)//// 找到x所在原树的根节点, 再将原树的根节点旋转到splay的根节点
{
    access(x);
    while(t[x].s[0]) pushdown(x),x=t[x].s[0];
    splay(x);
    return x;
}
void split(int x,int y) // 给x和y之间的路径建立一个splay，其根节点是y
{
    makeroot(x);
    access(y);
}
void link(int x,int y)
{
    makeroot(x);
    if(findroot(y)!=x)t[x].p=y;
}
void cut(int x,int y)
{
    makeroot(x);
    if(findroot(y)==x&&t[y].p==x&&!t[y].s[0])
    {
        t[x].s[1]=t[y].p=0;
        pushup(x);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>t[i].v;
    while(m--)
    {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==0)
        {
            split(x,y);
            cout<<t[y].sum<<endl;
        }
        else if(op==1) link(x,y);
        else if(op==2) cut(x,y);
        else
        {
            splay(x);
            t[x].v=y;
            pushup(x);
        }
    }
    return 0;
}
