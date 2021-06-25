//splay��֤����������������������䣬���ԭ��������Ϊ�ö��������������
//splay���õĶ�����Ϊ�����С�ڸ�����С���Ҷ��ӵĶ�����
/*
splay�İ���ֻ��rotate��splay����������������������������������ϳ����ġ�
����ɾ�����ǿ������ҵ�Ҫɾ���ڵ���������ǰ���ͺ�̣�Ȼ��ǰ����ת�������ٽ������ת��ǰ�������棬
���̽ڵ������Ӿ���Ҫɾ�������ݣ�ֱ��ɾ�����ɡ�
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N=100010;
int n,m; 
struct node
{
    int s[2],p,v; //s��ʾ���Ҷ���
    int size,lazy;//size��ʾ�Ը������Ĵ�С,lazyΪ�����
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
    if(t[x].lazy) //����Ǳ���Ƿ���Ҫ��ת
    {
        swap(t[x].s[0],t[x].s[1]);
        t[t[x].s[0]].lazy^=1;
        t[t[x].s[1]].lazy^=1;
        t[x].lazy=0;
    }
}
void rotate(int x) //��ת����
{
    int y=t[x].p,z=t[y].p; //y,z�ֱ��ʾx,y�ĸ��ڵ���
    int k=t[y].s[1]==x ;//k=0��ʾx��y�������,����Ϊ�Ҷ���
    t[z].s[t[z].s[1]==y]=x, t[x].p=z;//��y��z���Ҷ���,��x��Ϊz���Ҷ��ӣ���֮Ҳһ��
    t[y].s[k]=t[x].s[k^1] ,t[t[x].s[k^1]].p=y;//��k=0����˵��x���Ҷ���Ҳ��0^1��Ϊy�������.
    t[x].s[k^1]=y,t[y].p=x;//ͬʱ,k=0,y��Ϊx���Ҷ���,��֮���Ϊ�����
    pushup(y),pushup(x);
}
void splay(int x,int k)
{
    while(t[x].p!=k)
    {
        int y=t[x].p,z=t[y].p;
        if(z!=k)
            if((t[y].s[1]==x)^(t[z].s[1]==y)) rotate(x);//���������,����ת����x
            else rotate(y);//�����ֱ��,������תһ��y,����תx
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
int get(int k)//Ѱ�ҵ�k�����������������С���ұߣ�����߶�����С��K��˵��K���ұ�
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
    for(int i=0;i<=n+1;i++)insert(i); //����0��n+1�����ڱ�
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        l=get(l),r=get(r+2);
        splay(l,0),splay(r,l);//��l��ת������λ�ã���r��ת��l��λ��,r��Ϊl���µ�������
        t[t[r].s[0]].lazy^=1; //��r�����������Ǹ��£���Ϊr������ӱ�Ϊ��lԭ�����Ҷ���
    }
    output(root);
    return 0;
}
