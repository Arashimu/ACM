
//分块常用模板 
int g(int k, int x)
{
    return k / (k / x);
}

LL f(int a, int b, int k)
{
    a = a / k, b = b / k;
    LL res = 0;
    int n = min(a, b);
    for (int l = 1, r; l <= n; l = r + 1)
    {
        r = min(n, min(g(a, l), g(b, l)));
        res += (LL)(sum[r] - sum[l - 1]) * (a / l) * (b / l);
    }
    return res;
}

