#include<iostream>
using namespace std;
class A 
{
public:
	A() 
	{
		++_count;
	}
	A(const A& a) 
	{
		++_count;
	}
	//this ָ������壺ָ��ǰ���ô˺����Ķ���
	//static��Ա����������thisָ��
	//static��������ͨ���������ʣ�ͨ����������ʱ��û�ж���
	 static int getCount() 
	{
		 //ȱ��thisָ��,���ܵ���static��Ա����
		 //fun();
		return _count;
	}
	 void fun() 
	 {
		 getCount();
		 cout << "fun()" << endl;
	 }
private:
	static int _count;
};
//static��Ա�����ж�����
//static��Ա�����������ʼ��
int A::_count = 0;

A funA(A a) 
{
	return a;
}

void main() 
{
	A a;
	A b;
	A a1 = funA(a);
	cout << a1.getCount() << endl;
	cout << A::getCount() << endl;
}