//二维几何常用算法


//精度判断  (留坑) 



//1.判断点是否在多边形内:射线法 转角法 (常用)
 
 
 
 
 
 
 
 //计算凸包 Andrew算法 O(nlogn)
   
   //计算凸包，输入点数组p，个数为p，输出点数组ch。函数返回凸包的顶点数。
   //输入不能带有重复点。函数执行完后输入点的顺序被破坏
   //如果不希望在凸包的边上有输入点，吧两个<=改成<
   //在精度要求较高时建议用dcmp比较
 
 bool cmp(Point a,Point b)
 {
 	if(a.x!=b.x)return a.x<b.x;
	 else return a.y<b.y; 
 }
 //刘版本 
double Andrew (Point *p,int n,Point *ch)
{
	sort(p,p+n,cmp);
	int m=0;
	for(int i=0;i<n;i++)
	{
		while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
		ch[m++]=p[i];
	}   //求下凸包 
	int k=m;
	for(int i=n-2;i>=0;i--)
	{
		while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
		ch[m++]=p[i];
	} //求上凸包 
	if(n>1) m--;
	return m;
 } 
 //y总版本
 double Andrew()
{
    sort(p,p+n,cmp);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        while(cnt>=2&&area(p[s[cnt-1]],p[s[cnt]],p[i])<=0)
        {
            if(area(p[s[cnt-1]],p[s[cnt]],p[i])<0) st[s[cnt--]]=0;
            else cnt--;
        }
        s[++cnt]=i;
        st[i]=1;
    }
    st[0]=0;
    for(int i=n-1;i>=0;i--)
    {
        if(st[i]) continue;
        while(cnt>=2&&area(p[s[cnt-1]],p[s[cnt]],p[i])<=0)
        cnt--;
        s[++cnt]=i;
    } 
    } 
 
 //凸包的面积
 double area(int m)
 {
 	double ans=0;
 	for(int i=1;i<m-1;i++)
 	  ans+=Cross(ch[i]-ch[0],ch[i+1]-ch[0]);
 	  return fabs(ans/2);
  }
  
//求凸包的周长
double dist(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double length(int m)
{
	double ans=0;
	for(int i=0;i<m;i++)
	   ans+=dist(ch[i],ch[(i+1)%m]);  //%是为了处理最后一个点与第一个点相连 
	   return ans;
 } 
