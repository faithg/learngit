/**
 * @file bubble.c
 * @brief ð������
 * @author cui
 * @version 1.0
 * @date 2016-04-06
 */
#include<stdio.h>

/**
 * @brief ���ݽ�������
 *
 * @param a ����
 * @param b ����
 */
static void swap(int* a, int* b)
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}
/**
 * @brief ������
 *
 * @param arr ����������
 * @param count ���鳤��
 */
static void Bubble(int* arr, int count)
{
	int i,j;
	int flag;///���ñ�־λ,����������ѭ��.
	for(j=0; j<count; j++)
	{
		flag = 0;
		for(i=0; i<count-1; i++)
		{
			if(arr[i]>arr[i+1])
			{
				swap(&arr[i],&arr[i+1]); 
				flag = 1;
			}
		}
		if(flag == 0)
		  break;
	}
}

/**
 * @brief ������
 *
 * @return ����0.
 */
int main()
{
	int arr[10] = {1,3,2,6,8,41,12,7,4,19};
	int i;
	for(i=0; i<10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	Bubble(arr, 10);
	for(i=0; i<10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
