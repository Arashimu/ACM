//高维前缀和 O(n*2^n)
for(int j = 0; j < n; j++) 
    for(int i = 0; i < 1 << n; i++)
        if(i >> j & 1) f[i] += f[i ^ (1 << j)];
//a[j]可以统计出对于当前状态 j 的所有超集的状态和。
/*
举个例子a[1010]
 经过上述代码
 a[1010]=[1010]+[1011]+[1110]+[1111] 
