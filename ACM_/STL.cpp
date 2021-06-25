/*
upper_bound():返回的是被查序列中第一个大于查找值得指针；
lower_bound()：返回的是被查序列中第一个大于等于查找值的指针；


Vector:vector<int>v
v.push_back(x)  v.pop_back()  
vector<int>v(5)   //size为5，值默认为0
vector<int>v(5,1)  //size为5，值默认为1
for(int i=0;i<v.size();i++) cout<<a[i];
vector <int>::iterator it //定义一个vector的指针 
*/   

/* Set
set<int>s;
s.insert(v);
s.erase(s.find(v))/s.erase(v)
*s.begin()  //第一个元素的值
*s.rbegin()//第二个元素的值 
  
//Stack
stack<int>s;
s.push(a);
s.pop();
s.top() 栈顶元素
//


a[]为数组,n为a的大小 
*max_element(a,a+n) 查找a中最大的元素 

tuple 

//解锁string新用法 
 string ss;
        for(int k = 0; k < 5 && i + k < n; k++) {
            ss.push_back(s[i + k]);
