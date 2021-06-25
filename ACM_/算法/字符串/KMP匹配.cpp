//KMP字符串匹配 O(n+m) 在文本字符串S内查找一个词W的出现位置
 
//next数组计算
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
//f数组计算  求出模板串P在模式串S中所有出现的位置的起始下标
void calc_f()
{
	for(int i=1,j=0;i<=m;i++)
	{
		while(j>0&&(j==n||b[i]!=a[j+1])) j=next[j];
		if(b[i]==a[j+1]) j++;
		f[i]=j;
		//if(f[i]==n) 此时就是A在B中的某一次出现 
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
