//KMP�ַ���ƥ�� O(n+m) ���ı��ַ���S�ڲ���һ����W�ĳ���λ��
 
//next�������
void calc_next()
{
	next[1]=0;
	for(int i=2,j=0;i<=n;i++)
	{
		while(j>0&&a[i]!=a[j+1]) j=next[j];
		if(a[i]==a[j+1]) j++;
		next[i]=j;
	}
 } 
//f�������  ���ģ�崮P��ģʽ��S�����г��ֵ�λ�õ���ʼ�±�
void calc_f()
{
	for(int i=1,j=0;i<=m;i++)
	{
		while(j>0&&(j==n||b[i]!=a[j+1])) j=next[j];
		if(b[i]==a[j+1]) j++;
		f[i]=j;
		//if(f[i]==n) ��ʱ����A��B�е�ĳһ�γ��� 
	}
 } 
 
 /*
 
vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
	  */ 
