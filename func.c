#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

//C���Ա�׼�⺯��strcpy��һ�ֵ��͵Ĺ�ҵ�������ʵ�֡� 
//����ֵ��Ŀ�괮�ĵ�ַ��
//���ڳ����쳣�����ANSI-C99��׼��δ���壬����ʵ���߾�������ֵ��ͨ��ΪNULL��
//������desΪĿ���ַ�����sourceΪԭ�ַ�����

//ʹ�ÿ⺯��-->assert();
char* m_strcpy(char* dst, const char* src) {

	char* r = dst;

	assert((dst != NULL) && (src != NULL));

	while ((*src) != '\0') 
	{
		*dst++ = *src++;
	}

	return dst;
}


//memcpy:�ڴ濽������
void *m_memcpy(void *dst, const void *src, int n)
{
	assert((dst != NULL) && (src != NULL));
	
	char * pdst = (char *)dst;
	char * psrc = (char *)src;
	//��ֹ�ڴ��ص�
	if (pdst > psrc && pdst < psrc + n)
	{
		pdst = pdst + n - 1;
		psrc = psrc + n - 1;
		while (n--) 
		{
			*pdst-- = *psrc--;
		}
	}
	else
	{
		while (n--) 
		{
			*pdst++ = *psrc++;
		}
	}
	return dst;
}


//strncpy:��strcpy();�����������˿����ֽ���-->���Ӱ�ȫ��
char* m_strncpy(char* dest, const char* src, size_t n)

{
	assert((dest != NULL) && (src != NULL));
	char *tmp = dest;
    size_t i = 0;
	/*while (n--) 
	{
		*tmp++ = *src++;
	}*/
	while ((i++ < n) && (*tmp++ = *src++) != '\0');
	return dest;

}



int main()
{
	char str[50] = "1234567890";
	char *str1= "abcde";

	//m_strncpy(str, str1, 5);
	m_memcpy(str, str1, 3);//ע��n>sizeof(str1);����Խ�����
	//m_strcpy(str, str1);
	
	printf("%s\n", str);
	system("pause");
	return 0;
}
