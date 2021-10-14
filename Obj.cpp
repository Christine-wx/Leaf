#include<iostream>
#include<mutex>
using namespace std;

//ֻ���ڶ��ϴ�������
class Heapobj 
{
public:
	static Heapobj* creatObj() 
	{
		return new Heapobj();
	}
private:
	Heapobj() {}
	Heapobj(const Heapobj& obj) = delete;
	Heapobj& operator=(const Heapobj& obj) = delete;
};


//ֻ����ջ�ϴ�������
class Stackobj 
{
public:
	static Stackobj creatobj() 
	{
		return Stackobj();
	}
private:
	Stackobj() {}
};


//���ܱ�����
class Nocopy 
{
private:
	Nocopy(const Nocopy & obj) = delete;
	Nocopy & operator=(const Nocopy & obj) = delete;
};

class A final  
{
};


//����ģʽ��
//����ģʽ

//����ʽ
class Singleton
{
public:
	//��ȡΨһʵ���ľ�̬����
	static Singleton* getSingleton()
	{
		return &_singleton;
	}

private:
	//˽�й���
	Singleton() {};
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;

	static Singleton _singleton;
};
Singleton Singleton::_singleton;

//����ʽ
class Singleton
{
public:
	static Singleton* getSingleton()
	{
		if (_singleton == nullptr)
		{
			_mutex.lock();
			if (_singleton == nullptr)
			{
				_singleton = new Singleton();
			}
			_mutex.unlock();
		}
		return _singleton;
	}

private:
	Singleton() {};
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&)=delete;

	static mutex _mutex;//������
	static Singleton* _singleton;
};
Singleton* Singleton::_singleton = nullptr;
mutex Singleton::_mutex;



void *memcpy(void *dst, const void *src, unsigned int n)
{
	if (dst == NULL || src == NULL || n == 0)
		return NULL;

	char * pdst = (char *)dst;
	char * psrc = (char *)src;

	if (pdst > psrc && pdst < psrc + n)
	{
		pdst = pdst + n - 1;
		psrc = psrc + n - 1;
		while (n--)
			*pdst-- = *psrc--;
	}
	else
	{
		while (n--)
			*pdst++ = *psrc++;
	}
	return dst;
}




