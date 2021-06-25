//模拟退火 simulate_anneal
#include <cmath>
#include <ctime>
double rand(double l,double r) //随机生成一个l到r之间的数 
{
	return (double )rand()/RAND_MAX*(r-l) + l;
}
double calc(){}

void simulate_anneal()
{
	double cur_per=rand(l,r);
	for(double t=1e4;t>1e-4;t*=0.99) //t每次乘一个接近1的数最好
	{
		double next_per=rand(cur-t,cur+t);
		double delta=calc(next_per)-calc(cur_per);
		if(exp(-delta/t)>rand(0,1)) cur_per= next_per;//>是求最小值，若要求最大值 
	 } 
	 return;
}

int main()
{
	for(in ti=0;i<100;i++)simulate_anneal();
	//卡时法
	//if(clock()<time) simulate_anneal();
	return 0; 
}
