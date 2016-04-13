/**
 * @file heap.c
 * @brief 堆排序
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
 * @brief 先排成最小堆,再排序.
 *
 * @param arr 待排数组
 * @param len 数组长度 */
static void heap_min(int* arr, int len)
{
	int i;
	///从最后一个具有儿子的节点处查找.
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
	heap_min(arr, len);///先堆化
	swap(&arr[0], &arr[len-1]);///把最小值交换到末尾.
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
