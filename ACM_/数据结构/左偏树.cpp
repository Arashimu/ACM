//×óÆ«Ê÷
int v[N], dist[N], l[N], r[N], idx;
int v[0]=inf;
bool cmp(int x, int y)
{
    if (v[x] != v[y])return v[x] < v[y];
    else return x < y;
}
int merge(int x, int y)
{
    if (!x || !y)return x + y;
    if (cmp(y, x))swap(x, y);
    r[x] = merge(r[x], y);
    if (dist[r[x]] > dist[l[x]]) swap(l[x], r[x]);
    dist[x] = dist[r[x]] + 1;
    return x;
} 
int main()
{
	//²åÈë²Ù×÷ 
	v[++idx] = x;
    dist[idx] = 1;
            
}
