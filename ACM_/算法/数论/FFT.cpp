#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
const int N = 4e5+5;
const double pi = acos(-1);
int n, m;
struct Complex
{
    double a, b;
    Complex(double x=0, double y=0)
    {
        a = x, b = y;
    }
    Complex operator + (const Complex& t)const
    {
        return { a + t.a,b + t.b };
    }
    Complex operator - (const Complex& t)const
    {
        return { a - t.a,b - t.b };
    }
    Complex operator * (const Complex& t)const
    {
        return { a * t.a - b * t.b,a * t.b + b * t.a };
    }
} a[N], b[N];
void fft(Complex a[], int n, int f)
{
    if (n == 1)return;
    static Complex t[N];
    int mid = n >> 1;
    for (int i = 0; i < mid; i++)
        t[i] = a[i << 1],
        t[i + mid] = a[i << 1 | 1];
    memcpy(a, t, n << 4);

    memcpy(a, t, n << 4);

    fft(a, mid, f);
    fft(a + mid, mid, f);

    for (int i = 0, j = mid; i < mid; i++, j++)
    {
        Complex x = { cos(2 * pi * i / n),f * sin(2 * pi * i / n) };
        t[i] = a[i] + x * a[j];
        t[j] = a[i] - x * a[j];
    }
    memcpy(a, t, n << 4);
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        double x;
        cin >> x;
        a[i] = { x,0 };
    }
    for (int i = 0; i <= m; i++)
    {
        double x;
        cin >> x;
        b[i] = { x,0 };
    }
    int k = 1;
    while (k <= n + m)k = k << 1;
    fft(a, k, 1);
    fft(b, k, 1);
    for (int i = 0; i < k; i++) a[i] = a[i] * b[i];
    fft(a, k, -1);
    for (int i = 0; i <= n + m; i++)
        cout << (int)(a[i].a / k + 0.5) << " ";
    return 0;
}
