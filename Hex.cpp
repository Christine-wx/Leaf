#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<cmath>
using namespace std;

//������ת����ʮ����
int b2_int10(string str) {
	int sum = 0, t;
	for (int i = 0; i < str.size(); i++) {
		t = str[i] - '0';
		sum = 2 * sum + t;
	}
	return sum;
}

//ʮ����ת��������
int b10_int2(int num)
{
	int mod, res = 0, k = 1;
	while (num != 0)
	{
		mod = num % 2;
		num = num / 2;
		res = res + mod * k;
		k = k * 10;
	}
	return res;
}

//ʮ����ת����ʮ������
void b10_int16(int num) 
{
	vector<int> v;
	char s[] = "0123456789ABCDEF";

	     if (num == 0) {
		    v.push_back(0);
	     }
			
		while (num != 0)
		{
			v.push_back(num % 16);
			num /= 16;
		}

		vector<int>::reverse_iterator rit;
		for (rit = v.rbegin(); rit != v.rend(); rit++)
		{
			cout << s[*rit];
		}
}

//ʮ������ת����ʮ����
void b16_int10(string& str) 
{
	int n = str.size();
	int sum = 0;
	for (int i = n-1; i >= 0; i--)//��ʮ�����Ƹ�λ��ʼ��ÿλ��ת����ʮ����  
	{
		if (str[i] >= '0'&&str[i] <= '9')//�����ַ���ת��  
		{
			sum += (str[i] - 48)*pow(16, n - i - 1);
		}
		else if (str[i] >= 'A'&& str[i] <= 'F')//��ĸ�ַ���ת��  
		{
			sum += (str[i] - 55)*pow(16, n - i - 1);
		}
		else if (str[i] >= 'a'&& str[i] <= 'f')//��ĸ�ַ���ת��  
		{
			sum += (str[i] - 87)*pow(16, n - i - 1);
		}
	}
	cout << sum;
}






int main() {
	//cout << b2_int10("111");
	//b10_int16(19);
	string str;
	str = "13";
	b16_int10(str);
	return 0;
	}

