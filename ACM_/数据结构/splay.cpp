//splay保证左旋或右旋后中序遍历不变，因此原本的序列为该二叉树的中序遍历
//splay所用的二叉树为左儿子小于根，根小于右儿子的二叉树
/*
splay的板子只有rotate、splay两个函数，其他函数都是用这俩函数组合出来的。
比如删除，那可以先找到要删除节点或者区间的前驱和后继，然后将前驱旋转到根，再将后继旋转到前驱的下面，
则后继节点的左儿子就是要删除的内容，直接删掉即可。
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N=100010;
int n,m; 
struct node
{
    int s[2],p,v; //s表示左右儿子
    int size,lazy;//size表示以该子树的大小,lazy为懒标记
    void init(int v_,int p_)
    {
        v=v_,p=p_;
        size=1;
    }
}t[N];
int root,idx;
void pushup(int x)
{
    t[x].size=t[t[x].s[0]].size+t[t[x].s[1]].size+1;
}
void pushdown(int x)
{
    if(t[x].lazy) //懒标记标记是否需要旋转
    {
        swap(t[x].s[0],t[x].s[1]);
        t[t[x].s[0]].lazy^=1;
        t[t[x].s[1]].lazy^=1;
        t[x].lazy=0;
    }
}
void rotate(int x) //旋转函数
{
    int y=t[x].p,z=t[y].p; //y,z分别表示x,y的父节点编号
    int k=t[y].s[1]==x ;//k=0表示x是y的左儿子,否则为右儿子
    t[z].s[t[z].s[1]==y]=x, t[x].p=z;//若y是z的右儿子,则x变为z的右儿子，反之也一样
    t[y].s[k]=t[x].s[k^1] ,t[t[x].s[k^1]].p=y;//若k=0，则说明x的右儿子也即0^1变为y的左儿子.
    t[x].s[k^1]=y,t[y].p=x;//同时,k=0,y变为x的右儿子,反之则变为左儿子
    pushup(y),pushup(x);
}
void splay(int x,int k)
{
    while(t[x].p!=k)
    {
        int y=t[x].p,z=t[y].p;
        if(z!=k)
            if((t[y].s[1]==x)^(t[z].s[1]==y)) rotate(x);//如果是折链,则旋转两次x
            else rotate(y);//如果是直链,则先旋转一次y,在旋转x
        rotate(x);
    }
    if(!k) root=x;
}
void insert(int v)
{
    int u=root,p=0;
    while(u) p=u,u=t[u].s[v>t[u].v];
    u=++idx;
    if(p) t[p].s[v>t[p].v]=u;
    t[u].init(v,p);
    splay(u,0);
}
int get(int k)//寻找第k大的数，如果由于左边小于右边，若左边儿子数小于K，说明K在右边
{
    int u=root;
    while(true)
    {
        pushdown(u);
        if(t[t[u].s[0]].size>=k) u=t[u].s[0];
        else if(t[t[u].s[0]].size+1==k) return u;
        else k-=t[t[u].s[0]].size+1,u=t[u].s[1];
    }
    return -1;
}
void output(int u)
{
    pushdown(u);
    if(t[u].s[0]) output(t[u].s[0]);
    if(t[u].v>=1&&t[u].v<=n) cout<<t[u].v<<" ";
    if(t[u].s[1]) output(t[u].s[1]);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n+1;i++)insert(i); //加入0和n+1两个哨兵
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        l=get(l),r=get(r+2);
        splay(l,0),splay(r,l);//将l旋转到根的位置，将r旋转到l的位置,r作为l的新的右子树
        t[t[r].s[0]].lazy^=1; //将r的左儿子懒标记更新，因为r的左儿子变为了l原本的右儿子
    }
    output(root);
    return 0;
}
