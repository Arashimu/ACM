//��ά���γ����㷨


//�����ж�  (����) 



//1.�жϵ��Ƿ��ڶ������:���߷� ת�Ƿ� (����)
 
 
 
 
 
 
 
 //����͹�� Andrew�㷨 O(nlogn)
   
   //����͹�������������p������Ϊp�����������ch����������͹���Ķ�������
   //���벻�ܴ����ظ��㡣����ִ�����������˳���ƻ�
   //�����ϣ����͹���ı���������㣬������<=�ĳ�<
   //�ھ���Ҫ��ϸ�ʱ������dcmp�Ƚ�
 
 bool cmp(Point a,Point b)
 {
 	if(a.x!=b.x)return a.x<b.x;
	 else return a.y<b.y; 
 }
 //���汾 
double Andrew (Point *p,int n,Point *ch)
{
	sort(p,p+n,cmp);
	int m=0;
	for(int i=0;i<n;i++)
	{
		while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
		ch[m++]=p[i];
	}   //����͹�� 
	int k=m;
	for(int i=n-2;i>=0;i--)
	{
		while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
		ch[m++]=p[i];
	} //����͹�� 
	if(n>1) m--;
	return m;
 } 
 //y�ܰ汾
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
 
 //͹�������
 double area(int m)
 {
 	double ans=0;
 	for(int i=1;i<m-1;i++)
 	  ans+=Cross(ch[i]-ch[0],ch[i+1]-ch[0]);
 	  return fabs(ans/2);
  }
  
//��͹�����ܳ�
double dist(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double length(int m)
{
	double ans=0;
	for(int i=0;i<m;i++)
	   ans+=dist(ch[i],ch[(i+1)%m]);  //%��Ϊ�˴������һ�������һ�������� 
	   return ans;
 } 
