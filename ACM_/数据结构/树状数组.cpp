#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N=1e5+10;
int a[N],t[N];
int lowbit(int x)
{
	return x&-x;
}
int update(int i,int k)
{
	while(i<=n)
	{
		t[i]+=k;
		i+=lowbit(i);
	}
}
int query(int i)
{
	int ans=0;
	while(i>0)
	{
		ans+=t[i];
		i-=lowbit(i);
	}
}
int main()
{
	cin>>n>>m;
	//区间修改，单点查询
	/*a[0]=0;
	for(int i=1;i<=n;++i) cin>>a[i],update(i,a[i]-a[i-1]);
	while(m--)
	{
		int l,r,x,i;
		char op;
		cin>>op;
		if(op=='Q')
		{
			cin>>i;
			cout<<query(i);
		}
		else 
		{
			cin>>l>>r>>x;
			update(l,x);
			update(r+1,-x);
		}
	}*/
	//单点修改，单点查询
	/*for(int i=1;i<=n;i++) cin>>a[i],update(i,a[i]);
	while(m--)
	{
		char op;
		int i,x;
		if(op=='Q')
		{
			cin>>i;
			cout<<query(i)-query(i-1);
			//query(r)-query(l-1) 区间查询 
		}
		else
		{
			cin>>i>>x;
			update(i,x);
		}
	 } */
	return 0;
	 
}
