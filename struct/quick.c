/**
 * @file quick.c
 * @brief 快速排序
 * @author cui
 * @version 1.0
 * @date 2016-04-07
 */
#include<stdio.h>
#include<stdlib.h>

/**
 * @brief 交换函数
 *
 * @param a 
 * @param b
 */
static void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * @brief 排序函数
 *
 * @param arr 待排数组
 * @param begin
 * @param end
 */
static void Quick_sort(int* arr, int begin, int end)
{
	int i,j;
	int std = end;///arr[std]是基数,选择数组最后一位.
	if(begin<end)
	{
	i=begin;
	///for循环.
		for(j=begin; j<end; j++)
		{
			if(arr[j]<=arr[std])
			{
				swap(&arr[j],&arr[i++]);///小于技术的排在左边,i加1,碰到大于的i值不变.
			}
		}
	swap(&arr[i], &arr[std]);///最后基数与arr[i]交换,两边分别为小于和大于基数的数.
	std = i;
	Quick_sort(arr, 0, std-1);///左半部排序.
	Quick_sort(arr, std, end);///右半部排序.	
}

/**
 * @brief 主函数
 *
 * @return 0 */
int main()
{
	int arr[10] = {12,3,2,6,7,4,9,5,20,11};
	int i;
	for(i=0; i<10; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	Quick_sort(arr, 0, 9);
	for(i=0; i<10; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
