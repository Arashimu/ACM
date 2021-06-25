//龟速乘 (高精度乘法取模) O(logb)
#include <iostream>
using namespace std;
typedef long long ll;
ll a,b,p;
ll qadd(ll x,ll y,ll mod)
{
    ll res=0;
    while(y)
    {
        if(y&1) res=(res+x)%mod;
        x=(x+x)%mod;
        y>>=1;
    }
    return res;
}
int main()
{
    cin>>a>>b>>p;
    cout<<qadd(a,b,p)<<endl;
    return 0;
    
} 
