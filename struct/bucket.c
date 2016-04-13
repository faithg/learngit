/**
 * @file bucket.c
 * @brief 桶排序
 * @author cui
 * @version 1.0
 * @date 2016-04-11
 */
#include<stdio.h>
#include<stdlib.h>

///1000为数组所存数据的大小范围为0-999.
int buf[1000] = {0};
void bucket_sort(int* arr, int len)
{
	int i;
	///将数组arr[]中的数在buf[]对应的下标的元素加一.
	for(i=0; i<len; i++)
	{
		buf[arr[i]]++;
	}
	int j;
	for(i=0; i<1000; i++)
	  while(buf[i]--!=0)
		arr[j++] = i;
}


/**
 * @brief 主函数.
 *
 * @return 
 */
int main()
{
	int i;
	int arr[10] = {23,4,55,532,21,6,7,87,56,90};
	for(i=0; i<10; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	bucket_sort(arr, 10);
	for(i=0; i<10; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
