/**
 * @file quick.c
 * @brief ��������
 * @author cui
 * @version 1.0
 * @date 2016-04-07
 */
#include<stdio.h>
#include<stdlib.h>

/**
 * @brief ��������
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
 * @brief ������
 *
 * @param arr ��������
 * @param begin
 * @param end
 */
static void Quick_sort(int* arr, int begin, int end)
{
	int i,j;
	int std = end;///arr[std]�ǻ���,ѡ���������һλ.
	if(begin<end)
	{
	i=begin;
	///forѭ��.
		for(j=begin; j<end; j++)
		{
			if(arr[j]<=arr[std])
			{
				swap(&arr[j],&arr[i++]);///С�ڼ������������,i��1,�������ڵ�iֵ����.
			}
		}
	swap(&arr[i], &arr[std]);///��������arr[i]����,���߷ֱ�ΪС�ںʹ��ڻ�������.
	std = i;
	Quick_sort(arr, 0, std-1);///��벿����.
	Quick_sort(arr, std, end);///�Ұ벿����.	
}

/**
 * @brief ������
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
