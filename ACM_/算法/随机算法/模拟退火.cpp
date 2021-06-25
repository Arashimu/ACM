//ģ���˻� simulate_anneal
#include <cmath>
#include <ctime>
double rand(double l,double r) //�������һ��l��r֮����� 
{
	return (double )rand()/RAND_MAX*(r-l) + l;
}
double calc(){}

void simulate_anneal()
{
	double cur_per=rand(l,r);
	for(double t=1e4;t>1e-4;t*=0.99) //tÿ�γ�һ���ӽ�1�������
	{
		double next_per=rand(cur-t,cur+t);
		double delta=calc(next_per)-calc(cur_per);
		if(exp(-delta/t)>rand(0,1)) cur_per= next_per;//>������Сֵ����Ҫ�����ֵ 
	 } 
	 return;
}

int main()
{
	for(in ti=0;i<100;i++)simulate_anneal();
	//��ʱ��
	//if(clock()<time) simulate_anneal();
	return 0; 
}
