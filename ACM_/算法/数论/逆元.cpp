//除法逆元:解决除法取模问题，即求(a/b)%p的值 
/*

费马小定理：假如 p是质数，且 gcd(a,p)=1，那么 a^(p-1)≡1（mod p）。即：假如a是整数，p是质数，且a,p互质(即两者只有一个公约数1)，
那么a的(p-1)次方除以p的余数恒等于1。
逆元：对于a和p，若 a*b%p ≡1，则称 b为 a%p的逆元。

前提,p为质数，公约数为1

推导:
b^(p-1)%p=1(费马小定理)
b*b^(p-2)%p=1
(a/b)*b*b^(p-2)%p=a/b
a*(b^(p-2))%p=a/b 
-> a/b=a*(b^(p-2))%p

*/
int inv(int a,int b)
{
	return (a*quick_mi(b,p-2))%p;
}
//常用于组合问题 
ll C(ll m,ll n)
{
	return (((p[n]*quick_mi(p[m],mod-2))%mod)*quick_mi(p[n-m],mod-2))%mod;
}
for(int i=0;i<=N;i++) p[i]= i==0? 1 : (p[i-1]*i)%mod;
