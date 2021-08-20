#include<stdio.h>
#include<string.h>
#include <malloc.h>
#include"code.h"

//��ʼ��һ���յ�˳���
void initseqList(seqList* s1)
{
	if (s1 == NULL)
		return;
	s1->_data = NULL;
	s1->_size = 0;
	s1->_capacity = 0;
}

void seqListCheckCapacity(seqList* s1)
{
	if (s1->_size == s1->_capacity)
	{
		//�ռ�����������
		//1.���µĿռ�
		int newCapacity = s1->_capacity == 0 ? 1:2 *s1->_capacity;
		SLDataType* tmp = (SLDataType*)malloc(newCapacity * sizeof(SLDataType));

		//2.����
		if(tmp!=0)
		memcpy(tmp, s1->_data, sizeof(SLDataType)* s1->_size);

		//3.�ͷ�ԭ�еĿռ�
		free(s1->_data);
		s1->_data = tmp;

		//s1->_data= (SLDataType*)relloc(newCapacity * sizeof(SLDataType));

		//4.��������
		s1->_capacity = newCapacity;
	}

}

//��������ɾ�Ĳ�
//β�壺��˳������һ����Ч���ݵ�ĩβ�����µ�����
void seqListPushBack(seqList* s1, SLDataType val)
{
	if (s1 == NULL)
		return;
	//�������
	seqListCheckCapacity(s1);
	//β��
	s1->_data[s1->_size] = val;
	s1->_size++;
}


void seqListPushFront(seqList* s1, SLDataType val) 
{
	if (s1 == NULL)
		return;
	seqListCheckCapacity(s1);
	int end = s1->_size;
	while (end > 0)
	{
		s1->_data[end] = s1->_data[end - 1];
		--end;
	}
	s1->_data[0] = val;
	s1->_size++;
}


void seqListpopBack(seqList* s1)
{
	if (s1 == NULL)
		return;
	int end = s1->_size;
	if (s1->_size > 0)//��size��ǰ�ƶ���ʹ���ݲ��ɼ�
		end = end - 1;
		s1->_size--;
}

void seqListPopFront(seqList* s1)
{
	if (s1 == NULL || s1->_size == 0)
		return;
	int start = 1;
	while (start < s1->_size)
	{
		s1->_data[start - 1] = s1->_data[start];
		++start;
	}
	//����size;
	s1->_size--;
}

void seqListPrint(seqList* s1) 
{
	if (s1 == NULL)
		return;
	for (int i = 0; i <s1->_size; ++i)
	{
		printf("%d", s1->_data[i]);
	}
	printf("\n");
}

SLDataType seqListAt(seqList* s1, int pos) 
{
	return s1->_data[pos];
}

int seqListEmpty(seqList* s1)
{
	if (s1 == NULL || s1->_size == 0)
		return 0;
	else
		return 1;
}

int seqListSize(seqList* s1)
{
	if (s1 == NULL || s1->_size == 0)
		return 0;
	else
		return s1->_size;
}

void test()
{
	seqList s1;//ʵ����
	initseqList(&s1);
	seqListPushBack(&s1, 1);
	seqListPushBack(&s1, 2);
	seqListPushBack(&s1, 3);
	seqListPushBack(&s1, 4);
	seqListPrint(&s1);
	
	seqListPushFront(&s1, 0);
	seqListPrint(&s1);
	seqListPopFront(&s1);
	seqListPrint(&s1);
}
int main()
{
	test();
	return 0;
}