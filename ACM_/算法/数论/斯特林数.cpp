//第一类斯特林数
int main()
{
    int n,k;
    cin>>n>>k;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=k;j++)
    f[i][j]=(f[i-1][j-1]+(long long)(i-1)*f[i-1][j])%mod;
    cout<<f[n][k]<<endl;
    return 0;
}
// 第二类斯特林数
int main()
{
    int n,k;
    cin>>n>>k;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=k;j++)
    f[i][j]=(f[i-1][j-1]+(ll)j*f[i-1][j])%mod;
    cout<<f[n][k]<<endl;
    return 0;
}
