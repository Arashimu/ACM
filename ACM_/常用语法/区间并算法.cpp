/*
���䲢�㷨
p���� һ������������˵�x,y
�ֽ�p����˵��С�������� 
*/
#define x first
#define y second
pair<int,int>p[N];
sort(q, q + cnt);
    LL res = 0;
    int st = q[0].x, ed = q[0].y;
    for (int i = 1; i < cnt; i ++ )
        if (q[i].x <= ed) ed = max(ed, q[i].y);
        else
        {
            res += ed - st;
            st = q[i].x, ed = q[i].y;
        }
    res += ed - st;
