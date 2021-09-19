#include<iostream>
using namespace std;
//new��delete�ײ�ʵ��
struct ListNode
{
	void *operator new(size_t n)
	{
		cout << "operator new" << endl;
		allocator<ListNode> alloc;
		return alloc.allocate(1);
		cout << "memory pool allocate" << endl;
	}
	void operator delete(void* ptr)
	{
		cout << "operator delete" << endl;
		allocator<ListNode> alloc;
		alloc.deallocate((ListNode*)ptr,1);
		cout << "memory pool deallocate" << endl;
	}
	ListNode(int data = 1) 
		:_data(data)
	{
		cout << "ListNode(int)" << endl;
	}
	~ListNode() 
	{
		cout << "~ListNode()" << endl;
	}
private:
	int _data = 0;
	ListNode* _next = nullptr;
};


//��Ԫ��������Ԫ��
class A 
{
public:
	//��Ԫ��������������ĳ�Ա���������Է������˽�г�Ա
	//��ͨ���������Է������ڵ�����λ��
	//friend void operator<<(ostream& _cout, const A&a);
	friend ostream& operator<<(ostream& _cout, const A&a);
	friend istream& operator>>(istream& _cin, A &a);
	A(int a=1,int b=2,int c=3)
	:_a(a)
	,_b(b)
	,_c(c)
	{}
	/*void operator<<(ostream& _cout) 
	{
		_cout << _a << "-" << _b << "-" << _c << "-" << endl;
	}*/

	
private:
	int _a;
	int _b;
	int _c;
};
ostream& operator<<(ostream& _cout, const A&a)
{
	_cout << a._a << "-" << a._b << "-" << a._c << endl;
	return _cout;

}
istream& operator>>(istream& _cin, A &a) 
{
	_cin >> a._a >> a._b >> a._c ;
	return _cin;
}
//void operator<<(ostream& _cout,const A&a)
//{
//	_cout << a._a << "-" << a._b << "-" << a._c << endl;
//}
void test() 
{
	A a;
	A b;
	//a.operator<<();
	//a << cout;
	operator<<(cout, a);
	cout << a << a << a << endl;
	//����ռ�
	char* ptr = (char*)malloc(sizeof(char));
	
	//�����ռ��С
	char* ptr1 = (char*)realloc(ptr, 2 * sizeof(char));
	//�����µĿռ䣬���ܺ�malloc����
	char* ptr2 = (char*)realloc(NULL, sizeof(char));

	//ptrָ��Ŀռ䲻���ͷ�
	//ֻ����ʽrealloc����֮��Ŀռ䣬����realloc��ָ��ռ���ʽ�ͷ�
	free(ptr1);

	//����ռ�+�ռ�ȫ����ʼ��Ϊ0
	char* ptr3 = (char*)calloc(4, sizeof(char));

	//new,delete
	int* ptr4 = new int;//����ռ�
	int* ptr5 = new int(10);//����ռ�+��ʼ��
	delete ptr5;
	//�����ռ�:����10��Ԫ��
	int* arr = new int[10];
	delete[] arr;
}