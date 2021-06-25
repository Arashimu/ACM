/*BSGS
给定正整数a,b,p;且a与p互质
求满足 a^x ≡b (modp)的最小非负整数x*/ 
int BSGS(int a,int b,int p) //y属于[0,k-1],x属于[1,k]
{
         if(1%p==b%p) return 0; //特判t=0的情况
         int k=sqrt(p)+1;
         unordered_map<int,int>hash;
         for(int i=0,j=b%p;i<k;i++) //枚举a^y
         {
             hash[j]=i;
             j=(ll)j*a%p;
         }
         int ak=1;
         for(int i=0;i<k;i++) ak=(ll)ak*a%p;
         for(int i=1,j=ak;i<=k;i++)
         {
             if(hash.count(j)) return (ll)i*k-hash[j];
             j=(ll)j*ak%p;
         }
         return -1;
}
int main()
{
    int a,p,b;
    while(cin>>a>>p>>b,a||p||b)
    {
        int res=BSGS(a,b,p);
        if(res==-1)puts("No Solution");
        else printf("%d\n",res);
    }
    return 0;
}
//扩展BSGS 
/*
给定正整数a,b,p;
求满足 a^x ≡b (modp)的最小非负整数x
*/ 
const int inf=1e8;
int bsgs(int a,int b,int p)
{
    if(1%p==b%p)return 0;
    unordered_map<int,int>hash;
    int k=sqrt(p)+1;
    for(int y=0,j=b%p;y<k;y++)
    {
        hash[j]=y;
        j=(ll)j*a%p;
    }
    int ak=1;
    for(int i=1;i<=k;i++)ak=(ll)ak*a%p;
    for(int x=1,j=ak;x<=k;x++)
    {
        if(hash.count(j)) return k*x-hash[j];
        j=(ll)j*ak%p;
    }
    return -inf;
}
int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
int exbsgs(int a,int b,int p)
{
    b=(b%p+p)%p; //保证余数为正数
    if(1%p==b%p)return 0;
    int x,y;
    int d=exgcd(a,p,x,y);
    if(d>1)  //不断迭代知道a/d与p/d互质，转化为普通的BSGS
    {
        if(b%d)return -inf;
        exgcd(a/d,p/d,x,y);
        return exbsgs(a,(ll)b/d*x%(p/d),p/d)+1;
    }
    return bsgs(a,b,p);
}

int main()
{
    int a,p,b;
    while(cin>>a>>p>>b,a||p||b)
    {
        int res=exbsgs(a,b,p);
        if(res<0)puts("No Solution");
        else cout<<res<<endl;
    }
    return 0;
}


