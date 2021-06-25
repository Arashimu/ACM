/*��̬��:
 ֧�ֶϿ�x�� y�ı�,Ҳ֧������x��y,
 ��Ϊ��ߺ�ʵ�ߣ�ʵ����splayά��
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
void access(int x)//// ����һ���Ӹ���x��·����ͬʱ��x���splay�ĸ��ڵ�
{
    int z=x;
    for(int y=0;x;y=x,x=t[x].p)
    {
        splay(x);
        t[x].s[1]=y,pushup(x);//���
    }
    splay(z);
}
void makeroot(int x)
{
    access(x);
    pushrev(x);
}
int findroot(int x)//// �ҵ�x����ԭ���ĸ��ڵ�, �ٽ�ԭ���ĸ��ڵ���ת��splay�ĸ��ڵ�
{
    access(x);
    while(t[x].s[0]) pushdown(x),x=t[x].s[0];
    splay(x);
    return x;
}
void split(int x,int y) // ��x��y֮���·������һ��splay������ڵ���y
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
