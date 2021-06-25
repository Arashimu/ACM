/*
读入m行，但不确定每行的 元素个数 
sstream流读入 
*/ 
#include <sstream>
a[M][N];
string line;
getline(cin, line);
int col=0;
while (m -- )
{
    getline(cin, line);
    stringstream ssin(line);
    int cnt = 0, p;
    while (ssin >> p) a[col][cnt ++ ] = p;
    col++;
 } 


