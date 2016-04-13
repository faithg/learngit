/**
 * @file heap.c
 * @brief ������
 * @author cui
 * @version 1.0
 * @date 2016-04-08
 */
#include<stdio.h>

#define LEFT (int)(2*i+1)
#define RIGHT (int)(2*i+2)

static void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * @brief ���ų���С��,������.
 *
 * @param arr ��������
 * @param len ���鳤�� */
static void heap_min(int* arr, int len)
{
	int i;
	///�����һ�����ж��ӵĽڵ㴦����.
	for(i=(len/2-1); i>=0; i--)
	{
		if(RIGHT<len)
		{
			if((arr[i]>arr[LEFT]) && (arr[LEFT]<arr[RIGHT]))
			{
				swap(&arr[i], &arr[LEFT]);
			}
			else if((arr[i]>arr[RIGHT]) && (arr[LEFT]>arr[RIGHT]))
			{
				swap(&arr[i], &arr[RIGHT]);
			}
		}
		else if((LEFT<len) && (arr[i]>arr[LEFT]))
		{
			swap(&arr[i], &arr[LEFT]);
		}
	}
}

static void heap_sort(int* arr, int len)
{
	if(len!=1)
	{
	heap_min(arr, len);///�ȶѻ�
	swap(&arr[0], &arr[len-1]);///����Сֵ������ĩβ.
	heap_sort(arr, len-1);
	}
}

int main()
{
	int arr[10] = {2,3,1,34,21,6,28,90,33,4};
	int i,len;
	len = 10;
	for(i=0; i<len; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	heap_sort(arr, len);
	for(i=0; i<len; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
