/*
upper_bound():���ص��Ǳ��������е�һ�����ڲ���ֵ��ָ�룻
lower_bound()�����ص��Ǳ��������е�һ�����ڵ��ڲ���ֵ��ָ�룻


Vector:vector<int>v
v.push_back(x)  v.pop_back()  
vector<int>v(5)   //sizeΪ5��ֵĬ��Ϊ0
vector<int>v(5,1)  //sizeΪ5��ֵĬ��Ϊ1
for(int i=0;i<v.size();i++) cout<<a[i];
vector <int>::iterator it //����һ��vector��ָ�� 
*/   

/* Set
set<int>s;
s.insert(v);
s.erase(s.find(v))/s.erase(v)
*s.begin()  //��һ��Ԫ�ص�ֵ
*s.rbegin()//�ڶ���Ԫ�ص�ֵ 
  
//Stack
stack<int>s;
s.push(a);
s.pop();
s.top() ջ��Ԫ��
//


a[]Ϊ����,nΪa�Ĵ�С 
*max_element(a,a+n) ����a������Ԫ�� 

tuple 

//����string���÷� 
 string ss;
        for(int k = 0; k < 5 && i + k < n; k++) {
            ss.push_back(s[i + k]);
