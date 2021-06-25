//gcd�����Լ��
int gcd(int a,int b)
{
	return b==0?a:gcd(a%b,a);
 }
 
 //������ 
 int quick_mi(int a,int b)
 {
 	int ans=1;
 	while(b)
 	{
 		if(b&1) ans=(ans*a)%mod;
 		b>>=1;
 		a=(a*a)%mod;
	 }
	 return ans;
 }
 
 //����ɸ
 int primes[N], cnt;     // primes[]�洢��������
bool st[N];         // st[x]�洢x�Ƿ�ɸ��

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
//Լ��������Լ��֮��
/* 
��� N = p1^c1 * p2^c2 * ... *pk^ck
Լ�������� (c1 + 1) * (c2 + 1) * ... * (ck + 1)
Լ��֮�ͣ� (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck) 
*/ 

//��ŷ������     ��(n) = n(1-1/p_1)(1-1/p_2)....(1-1/p_k)  
int phi(int x)
{
    int res = x;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);

    return res;
} 

//ɸ����ŷ������ 
int primes[N], cnt;     // primes[]�洢��������
int euler[N];           // �洢ÿ������ŷ������
bool st[N];         // st[x]�洢x�Ƿ�ɸ��


void get_eulers(int n)
{
    euler[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i])
        {
            primes[cnt ++ ] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0)
            {
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
}


// ��չŷ������㷨  
// ��x, y��ʹ��ax + by = gcd(a, b)
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1; y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a/b) * x;
    return d;
}

//��˹��Ԫ 
// a[N][N]���������
int gauss()
{
    int c, r;
    for (c = 0, r = 0; c < n; c ++ )
    {
        int t = r;
        for (int i = r; i < n; i ++ )   // �ҵ�����ֵ������
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;

        if (fabs(a[t][c]) < eps) continue;

        for (int i = c; i <= n; i ++ ) swap(a[t][i], a[r][i]);      // ������ֵ�����л������
        for (int i = n; i >= c; i -- ) a[r][i] /= a[r][c];      // ����ǰ�ϵ���λ���1
        for (int i = r + 1; i < n; i ++ )       // �õ�ǰ�н��������е�������0
            if (fabs(a[i][c]) > eps)
                for (int j = n; j >= c; j -- )
                    a[i][j] -= a[r][j] * a[i][c];

        r ++ ;
    }

    if (r < n)
    {
        for (int i = r; i < n; i ++ )
            if (fabs(a[i][n]) > eps)
                return 2; // �޽�
        return 1; // ����������
    }

    for (int i = n - 1; i >= 0; i -- )
        for (int j = i + 1; j < n; j ++ )
            a[i][n] -= a[i][j] * a[j][n];

    return 0; // ��Ψһ��
}

/*
Lucas���� 
��p��������������������� 1 <= m <= n���У�C(n, m) = C(n % p, m % p) * C(n / p, m / p) (mod p)
*/
int qmi(int a, int k)       // ������ģ��
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}


int C(int a, int b)     // ͨ�������������C(a, b)
{
    int res = 1;
    for (int i = 1, j = a; i <= b; i ++, j -- )
    {
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p - 2) % p;
    }
    return res;
}


int lucas(LL a, LL b)
{
    if (a < p && b < p) return C(a, b);
    return (LL)C(a % p, b % p) * lucas(a / p, b / p) % p;
}


