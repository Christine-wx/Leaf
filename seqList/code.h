#include<stdio.h>
#define N 100
typedef int SLDataType;

//sequence list
//��̬˳��� <����Ҫ�����ж�>
//��ռ��ջ�ϵĿռ䣬�����Դ�˷�
//sizeof(seqList):404byte;
//struct seqList1 
//{
//	SLDataType _data[N];
//	int _size;
//};

//��̬˳���
//sizeof(seqList):12byte;
typedef struct seqList
{
	SLDataType* _data;//����ָ��
	int _size;//��Ч��Ԫ�صĸ���
	int _capacity;//����Ŀռ�
}seqList;


void initseqList(seqList* s1);
//��������ɾ�Ĳ�
//β�壺��˳������һ����Ч���ݵ�ĩβ�����µ�����
//�ӿڣ�������������
//β��
void seqListPushBack(seqList* s1, SLDataType val);
//ͷ��
void seqListPushFront(seqList* s1, SLDataType val);
//�������
void seqListCheckCapacity(seqList* s1);
//βɾ
void seqListpopBack(seqList* s1);
//ͷɾ
void seqListPopFront(seqList* s1);
//��ӡ����
void seqListPrint(seqList* s1);

SLDataType seqListAt(seqList* s1, int pos);
//�п�
int seqListEmpty(seqList* s1);
//�����Ч���ݴ�С
int seqListSize(seqList* s1);