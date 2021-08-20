#include<string>
#include<iostream>
#include<assert.h>
#define  _CRT_SECCURE_NO_WARNINGS
using namespace std;


class String
{
public:
	//String ������������Ԫ��
	//ʵ�֣��ַ�ָ��
	typedef char* iterator;
	typedef const char* const_iterator;

	iterator begin()
	{
		//��һ��Ԫ�ص�λ��
		return _data;
	}

	const_iterator begin() const
	{
		//��һ��Ԫ�ص�λ��
		return _data;
	}

	iterator end()
	{
		//���һ��Ԫ�ص���һ��λ��
		return _data + _size;
	}

	const_iterator end() const
	{
		//���һ��Ԫ�ص���һ��λ��
		return _data + _size;
	}

	//���캯��
	//�����κβ�������һ���յ��ַ���
	String(const char* str = "")
		//�ռ������
		:_size(strlen(str))
		, _capacity(_size)
		, _data(new char[_size + 1])
	{
		//���ݵĿ���
		strcpy(_data,str);
	}

	//��������-->���ÿ������߼�
	String(const String& str)
		:_size(0)
		, _capacity(0)
		, _data(nullptr)
	{
		//�������캯���ڴ����ֲ�����ʱ�����пռ����� + ���ݿ���
		//������ʱ����
		String tmp(str._data);
		//ͨ��������Ա��ָ�����մﵽ���������Ŀ��
		Swap(tmp);
	}

	//��������
	void Swap(String& str)
	{
		swap(_size, str._size);
		swap(_capacity, str._capacity);
		swap(_data, str._data);

	}  

	//��ֵ����� --> ���ÿ���
	//��������������ɣ����пռ����� + ���ݿ���
	//�����ֲ����������������ɵ�ǰ����ԭ����Դ���ͷ�
	String& operator=(String str)
	{
		Swap(str);
		return *this;
	}

	//��������
	~String()
	{
		if (_data)
		{
			delete[] _data;
			_data = nullptr;
			_size = _capacity = 0;
		}
	}

	//��ȡ�ַ��ĸ���
	size_t size() const
	{
		return _size;
	}

	//��ȡ������С
	//const��ʾ�κζ��󶼿��Ե�������ӿ�
	size_t capacity() const
	{
		return _capacity;
	}

	//��[]��ʽ������Ԫ��
	char& operator[](size_t pos)
	{
		assert(pos < _size);
		return _data[pos];
	}

	const char& operator[](size_t pos) const
	{
		assert(pos < _size);
		return _data[pos];
	}

	//β��һ���ַ�
	void pushBack(const char& ch)
	{
		//û�п���ռ�
		if (_size == _capacity)
		{
			//����: 2��
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			reserve(newC);
		}

		//�����п���ռ�
		_data[_size] = ch;
		++_size;
		_data[_size] = '\0';
	}

	void reserve(size_t n)
	{
		//ֻ��������
		if (n > _capacity)
		{
			//1�����ٿռ�
			char* tmp = new char[n + 1]; //��ĩβ\0��λ��Ԥ������
			//2����������
			strcpy(tmp, _data);
			//3���ͷ�ԭ�пռ�
			delete[] _data;

			//���³�Ա
			_data = tmp;
			_capacity = n;
		}
	}

	//�ı��ַ�����������������λ�ý������
	void resize(size_t n, const char& ch = '\0')
	{
		//n > _capacity
		if (n > _capacity)
			//����
			reserve(n);

		//_size < n <= _capacity������ַ�
		/*for (size_t pos = _size; pos < n; ++pos)
		_data[pos] = ch;*/
		if (n > _size)
			//��ʼλ�ã������ֵ����С
			memset(_data + _size, ch, sizeof(char)*(n - _size));

		//n <= _size
		_size = n;
		//��ĩβ�ַ����'\0'��ʾ�ַ�������
		_data[_size] = '\0';
	}

	//׷���ַ���
	void append(const char* str)
	{
		//1���������
		int len = strlen(str);
		if (_size + len > _capacity)
			reserve(_size + len);
		//2������ O(n)
		memcpy(_data + _size, str, sizeof(char)*len);
		//strcpy(_data + _size,str)  O(n),���\0Ҳ������ȥ��Ч��û���ڴ濽����Ч
		//3������
		_size += len;
		_data[_size] = '\0';
	}

	String& operator+=(const String& str)
	{
		//String���� str
		append(str._data);
		return *this;
	}

	String& operator+=(const char* str)
	{
		//�ַ��� str
		append(str);
		return *this;
	}

	String& operator+=(const char ch)
	{
		//�ַ� ch
		pushBack(ch);
		return *this;
	}

	const char* c_str() const
	{
		return _data;
	}

	void insert(size_t pos,const char& ch)//�������֣��ַ�
	{
		assert(pos <= _size);//����
		if (_size == _capacity)//�������
		{
			size_t newC = _capacity == 0 ? 15 : 2 * _capacity;
			   reserve(newC);

		}
		//�ƶ�Ԫ��[pos,size]
        //�Ӻ���ǰ              //bugд����
		size_t end = _size + 1;//  size_t end=_size;
		while (end>pos )       //  while(end>=pos)
		{
			_data[end] = _data[end - 1]; //_data[end]=_data[end+1];  //����취�� int size_end=_size;
			--end;
		}
		//���룺pos
		_data[pos] = ch;
		//����size
		++_size;

	}
	/*
	void insert(size_t pos, const char& ptr)//�����ַ�������
	{
		assert(pos<= _size);//����
		int len = strlen(ptr);
		if (_size+len > _capacity)//�������
		{
			reserve(_size + len);
		}
		//�ƶ�Ԫ��
		//[pos,size]
		size_t end = _size + len;
		while (end>pos+len-1)
		{
			_data[end] = _data[end - len]; 
			--end;
		}
		//����
	  memcpy(_data + pos, ptr, size_t);
	    //����
			_size += len;
		_data[_size] = '\0';
	}
	*/
	void erase(size_t pos, size_t len)//ɾ������
	{
		assert(pos < _size);//����
		//Ҫɾ����Ԫ�ظ���С��ʣ���ַ��ĸ���
		if (pos + len >= _size)
		{
			_size = pos;
		_data[_size]= '\0';
		}
		else{
			//�ƶ�Ԫ��
			//��ǰ����ƶ�[pos+len,size]
			size_t start = pos + len;
			for (; start <= _size; ++start)
			{
				_data[pos++] = _data[start];	
			}
			_size = len;
		}
	}


	size_t find(const char& ch, size_t pos = 0)//�����ַ�
	{
		for (size_t i = 0; i < _size; ++i)
		{
			if (_data[i] == ch)
				return i;
		}
		return npos;
	}
	/*
	size_t find(const char& str,size_t pos)//�����ַ���
	{
		char* ptr = strstr(_data, str);
		if (ptr)
		{
			return ptr - _data;
		}
		return npos;
	}
	*/
private:
	//size����Ч�ַ��ĸ���
	size_t _size;
	//capacity:���Ĵ���ַ��ĸ���
	size_t _capacity;
	char* _data;
	static const size_t npos;
};

const size_t String::npos = -1;
ostream& operator<<(ostream& out,String str)
{
	for (const auto& ch : str)
	{
		out << ch;
		return out;
	}
}



//�����޸Ĳ�����������
String operator+(const String& str1, const String& str2)
{
	String str = str1;
	str += str2;
	return str;
}

String operator+(const char* str1, const String& str2)
{
	//��str1�ַ�������һ��String���󣬵��ù��캯��
	String str(str1);
	str += str2;
	return str;
}


String operator+(const char ch, const String& str2)
{
	String str = str2;
	str += ch;
	return str;
}

int main()
{
	string str;
	system("pause");
	return 0;
}
/*String operator+(const char* str1, const String& str2)
{
	String copy(str1);
	copy += str2;
	return copy;
}
*/
/*
String operator+(const char* str1, const String& str2)
{
	String str;
	str += str1;
	str += str2;
	return str;
}
*/
/*
String operator+(const char* ch, const String& str2)
{
	String copy(str2);
	copy +=ch;
	return copy;
}
*/

void printString(const String& str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		cout << str[i] << " ";
		//const char& operator[](size_t pos) const
		//�����޸�����
		//str[i] = i + 'a';


		/*
		String str;//ͷ��

		str.insert(0, 6);//6
		str.insert(1, 7);//67
		str.insert(1,'a');//6a7
		str.append("56789023456789");//6a756789023456789
		*/

		/*String  str("789");
		str.insert(3,'assd');
		str.insert(5, 'qfr');*/
		
		String str;
		str.erase(5, 3);

	}
}



/*
void test(){
string str = "12345";
string::reverse_iterator it = str.rbegin();
while (it != str.rend())
{
cout << "*it" << "";
++it;

}
}

int main()
{
test();
system("pause");
return 0;
}


*/

/*void test()
{
string str;
string copy(str);
string str2("abc");
string substr(str2, 1, 2);
string str3("12345678",5);
string str4(10, 'a');
string str5 = "abcde";//���ι������ʽ����ת��

}

int main()
{
test();
system("pause");
return 0;
}

*/



















