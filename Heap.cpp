//������:<1> ����ʵ��
//       <2> ���ȼ�����ʵ��
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void adjust_max(vector<int>& v, int root, int size) 
{
	int temp =v[root];
	for (int left = 2 * root + 1; left < size; left = 2 * left+1)
	{
		if (left + 1 < size && v[left] < v[left + 1]) 
		{
			left++;
		}
		if (v[left] > temp) 
		{
			v[root] = v[left];
			root = left;
		}
		else 
		{
			break;
		}
	}
	v[root] = temp;
}

void adjust_min(vector<int>& v, int root, int size)
{
	int temp = v[root];
	for (int left = 2 * root + 1; left < size; left = 2 * left + 1)
	{
		if (left + 1 < size && v[left] > v[left + 1])
		{
			left++;
		}
		if (v[left] < temp)
		{
			v[root] = v[left];
			root = left;
		}
		else
		{
			break;
		}
	}
	v[root] = temp;
}
void heapsort(vector<int>& v) 
{
	//��С��->����
	int size = v.size();
	//�����һ����Ҷ�ӽڵ㿪ʼ����
	for (int i = size / 2 - 1; i >= 0; --i)
	{
		//adjust_max(v, i, size);
		adjust_min(v, i, size);
	}
	//������-->�����Ĳ�ͬ-->����˳��ͬ
	for (int i = v.size() - 1; i>0; --i) 
	{
		swap(v[0], v[i]);
		//adjust_max(v,0,i);
		adjust_min(v, 0, i);
	}
}

//���ȼ�����ʵ��-->��С��
//�����->����
void heapsort_max(vector<int>& v) 
{
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < v.size(); ++i) 
	{
		q.push(v[i]);
	}
	for (int j = 0; j < v.size(); ++j) 
	{
		v[j] = q.top();
		q.pop();
	}
}

//С����->����
void heapsort_min(vector<int>& v)
{
	priority_queue<int> q;
	for (int i = 0; i < v.size(); ++i)
	{
		q.push(v[i]);
	}
	for (int j = 0; j < v.size(); ++j)
	{
		v[j] = q.top();
		q.pop();
	}
}
int main() 
{
	vector<int> v1;
	v1.emplace_back(49);
	v1.emplace_back(38);
	v1.emplace_back(65);
	v1.emplace_back(97);
	v1.emplace_back(76);
	v1.emplace_back(13);
	v1.emplace_back(27);
	heapsort(v1);
	for (auto &it : v1)
	{
		cout << it << " ";
		++it;
	}
	cout << endl;
	return 0;
}

