/*
����m�У�����ȷ��ÿ�е� Ԫ�ظ��� 
sstream������ 
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


