#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e6 + 5;
int n, m;
char s[N];
int sa[N], x[N], y[N], rk[N], height[N], c[N];
void get_sa()
{
    //基数排序o(n)
    //先对第一关键字(模式串出现的字母)排序
    for (int i = 1; i <= n; i++) c[x[i] = s[i]]++;
    for (int i = 2; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i > 0; i--)  sa[c[x[i]]--] = i;

    for (int k = 1; k <= n; k <<= 1)
    {
        int num = 0;
        for (int i = n - k + 1; i <= n; i++) y[++num] = i; //以长度为k,i为第一关键字,i+k为第二关键字
        for (int i = 1; i <= n; i++)
            if (sa[i] > k) y[++num] = sa[i] - k;

        //对第二关键字排序
        for (int i = 1; i <= m; i++) c[i] = 0;
        for (int i = 1; i <= n; i++) c[x[i]]++;
        for (int i = 2; i <= m; i++) c[i] += c[i - 1];
        for (int i = n; i; i--)  sa[c[x[y[i]]]--] = y[i], y[i] = 0;
        swap(x, y);
        x[sa[1]] = 1, num = 1;
        for (int i = 2; i <= n; i++)
            x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]) ? num : ++num;
        if (num == n)break;
        m = num;
    }
}


void get_height()
{
    for (int i = 1; i <= n; i++) rk[sa[i]] = i;
    for (int i = 1, k = 0; i <= n; i++)       //利用 height[rk[i]]>= height[rk[i-1]]-1
    {
        if (rk[i] == 1) continue;
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
     
        height[rk[i]] = k;
    }
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1), m = 122;//字母z的ASCLL值为122；
    get_sa();
    get_height();

    for (int i = 1; i <= n; i++) cout << sa[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++) cout << height[i] << " ";
    cout << endl;
    return 0;
}


/* 快速排序发(nlogn)
for (i = 1; i <= n; ++i) sa[i] = i, rk[i] = s[i];

  for (w = 1; w < n; w <<= 1) {
    sort(sa + 1, sa + n + 1, [](int x, int y) {
      return rk[x] == rk[y] ? rk[x + w] < rk[y + w] : rk[x] < rk[y];
    });  // 这里用到了 lambda
    memcpy(oldrk, rk, sizeof(rk));
    // 由于计算 rk 的时候原来的 rk 会被覆盖，要先复制一份
    for (p = 0, i = 1; i <= n; ++i) {
      if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
          oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) {
        rk[sa[i]] = p;
      } else {
        rk[sa[i]] = ++p;
      }  // 若两个子串相同，它们对应的 rk 也需要相同，所以要去重
    }
  }

  for (i = 1; i <= n; ++i) printf("%d ", sa[i]);
  */ 
