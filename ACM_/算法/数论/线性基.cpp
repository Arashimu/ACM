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
    for(int i=62;i>=0;i--) //�����Ķ����ƿ���һ��62ά������
    {
        for(int j=k;j<n;j++)
        if(s[j]>>i&1)   //���ҵ����������λ��1����
        {
            swap(s[j],s[k]);
            break;
        }
        if(!(s[k]>>i&1)) continue;  //���û�ҵ���˵����n������������ɵľ����i��ȫΪ0
        for(int j=0;j<n;j++)
         if(j!=k&&(s[j]>>i&1))       //��������еĵ�i��Ԫ��ȫ��Ϊ0
         s[j]^=s[k];
         k++;   //ǰK�о������Ի�
         if(n==k) break;
    }
    ll res=0;
    for(int i=0;i<k;i++)res^=s[i];
    cout<<res<<endl;
    return 0;
}

//���xС����
reverse(a,a+k);
 LL res = 0;
for (int i = 0; i < k; i ++ )
    if (x >> i & 1)
        res ^= a[i]; 
