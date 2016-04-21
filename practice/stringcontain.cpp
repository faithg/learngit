/**
 * @file stringcontain.cpp
 * @brief �����ַ�����������
 * @author cui
 * @version 1.0
 * @date 2016-04-05
 */
#include<stdio.h>
#include<string.h>

/**
 * @brief b�Ƿ���a��,26λ��ʾ26����д��ĸ,Ȼ��
 * �ټ��b�е��ַ����Ƿ���hash��.
 *
 * @param a �ַ���
 * @param b �ַ���
 * 
 * @return ��������true;����������false. 
 * */
bool StringContain(char *a, char *b)
{
	int hash = 0;
	int i;
	for(i=0; i<strlen(a); i++)
	{
		hash |= (1 << (a[i] - 'A'));
	}
	for(i=0; i<strlen(b); i++)
	{
		if((hash & (1 << (b[i] - 'A'))) == 0)
		  return false;
	}
	return true;
}

int main()
{
	char a[10] = "ASDFGHJKL";
	char b[5] = "ASHJ";
	char c[5] = "ASZC";
	bool b1, b2;
	b1 = StringContain(a,b);
	b2 = StringContain(a,c);
	printf("b1 = %d\n", b1);
	printf("b2 = %d\n", b2);
	return 0;
}

