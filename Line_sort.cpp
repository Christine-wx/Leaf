//���ԷǱȽ�����
//	1.��������-->O(n+k)-O(n+k),O(k)-----�ȶ�
//	2.��������-->O(n*k)-O(n*k),O(n+k)---�ȶ�
//  3.Ͱ����  -->O(n+k)-O(n^2),O(n+k)---�ȶ�

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

//��������
void countsort(vector<int>& v)
{
	if (v.size() < 2) return;
	//�ҳ��������鷶Χ
	int max = *(max_element(v.begin(), v.end()));
	int min = *(min_element(v.begin(), v.end()));
	//�����������
	vector<int> v_count(max - min + 1, 0);
	for (int i = 0; i < v.size(); ++i)
	{
		v_count[v[i] - min]++;
	}
	int idx = 0;
	for (int j = 0; j <v_count.size(); ++j) {
		int n = v_count[j];
		while (n--) {
			v[idx++] = j + min;
		}
	}
}

//Ͱ����
void bucketsort(vector<int>& v,int bkcount) 
{
	if (v.size() < 2) return;
	
	//�ҳ�������max,min;
	int max = *(max_element(v.begin(), v.end()));
	int min = *(min_element(v.begin(), v.end()));
	
	//���������Ԫ�ط����ӦͰ��
	vector<vector<int>>bucket(bkcount);
	int bksize = ceil((double)(max - min + 1) / bkcount);
	for (int i = 0; i < v.size(); ++i) 
	{
		int bkIdx = (v[i] - min) / bksize;
		bucket[bkIdx].emplace_back(v[i]);
	}

	//��Ͱ�е�Ԫ�ؽ�������
    //��Ͱ������õ�Ԫ�ؽ��в������飻
	int idx = 0;
	for (int i = 0; i < bucket.size(); ++i)
	{
		sort(bucket[i].begin(),bucket[i].end());
		//һ��sort�����ǿ���
		for (auto& val : bucket[i]) 
		{
			v[idx++] = val;
		}
	}
}


//��������
void RadixSort(vector<int>& v) {
	//���λ��
	int k = 0;
	for (int i = 0; i < v.size(); ++i)
		k = max(int(log(v[i])) + 1, k);
	for (int i = 0; i < k; ++i) {
		//ʮ����
		vector<vector<int>>radix(10);
		//����
		for (int j = 0; j < v.size(); ++j) {
			int index = int(v[j] / pow(10, i)) % 10;
			radix[index].push_back(v[j]);
		}
		int index = 0;
		//�ռ�
		for (int j = 0; j < radix.size(); ++j) {
			for (auto& val : radix[j]) {
				v[index++] = val;
			}
		}
	}
}


int main() 
{
	vector<int> v1 = {1, 9, 21 , 23, 14, 27, 35, 44};
	//ountsort(v1);
	//bucketsort(v1, v1.size() / 2);
	RadixSort(v1);
	for (auto &it : v1) 
	{
		cout << it << " ";
		++it;
	}
	cout << endl;
	return 0;
}








