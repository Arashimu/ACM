#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
const int N=1e5+5;
ll s[N],a[65];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    int k=0;
    for(int i=62;i>=0;i--) //将数的二进制看成一个62维行向量
    {
        for(int j=k;j<n;j++)
        if(s[j]>>i&1)   //先找到二进制最高位是1的数
        {
            swap(s[j],s[k]);
            break;
        }
        if(!(s[k]>>i&1)) continue;  //如果没找到，说明这n个数二进制组成的矩阵第i列全为0
        for(int j=0;j<n;j++)
         if(j!=k&&(s[j]>>i&1))       //将下面的行的第i个元素全变为0
         s[j]^=s[k];
         k++;   //前K行就是线性基
         if(n==k) break;
    }
    ll res=0;
    for(int i=0;i<k;i++)res^=s[i];
    cout<<res<<endl;
    return 0;
}

//求第x小的数
reverse(a,a+k);
 LL res = 0;
for (int i = 0; i < k; i ++ )
    if (x >> i & 1)
        res ^= a[i]; 
