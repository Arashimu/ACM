#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N=1e6+5;
long long a[N];
int n,k;
deque<int>min_q,max_q;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        while(min_q.size()&&min_q.front()<i-k+1) min_q.pop_front();
        while(min_q.size()&&a[min_q.back()]>=a[i]) min_q.pop_back();
        min_q.push_back(i);
        if(i>=k)cout<<a[min_q.front()]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        while(max_q.size()&&max_q.front()<i-k+1) max_q.pop_front();
        while(max_q.size()&&a[max_q.back()]<=a[i]) max_q.pop_back();
        max_q.push_back(i);
        if(i>=k)cout<<a[max_q.front()]<<" ";
    }
    return 0;
    
}
