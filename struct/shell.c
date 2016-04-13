/**
 * @file shell.c
 * @brief 在直接插入排序基础上改成希尔排序.
 * @author cui
 * @version 1.0
 * @date 2016-04-07
 */
#include<stdio.h>

static void Shell_sort(int* arr, int len)
{
	int i,j,k;///变量.
	int incre;///希尔排序的增量,每次二倍递减.
	int flag;
	for(incre=len/2; incre>0; incre/=2)
	{
		flag = 0;
	for(i=incre; i<len; i++)
	{
		for(j=i-incre; j>=0; j-=incre)
		  if(arr[j]<arr[i])
		  {
			flag = 1;
			break;
		  }

		if(j!=i-incre)
		{
			int tmp = arr[i];
			for(k=i-incre; k>j; k-=incre)
			{
				arr[k+incre] = arr[k];
			}
			arr[k+incre] = tmp;
		}
	}
	if(flag==0)
	  break;
	}
}

int main()
{
	int arr[30] = {201,3,14,12,8,68,4,9,8,7,1,2,3,4,5,6,7,8,9,10,20,19,18,17,16,15,14,13,12,11};
	int i;
	for(i=0; i<30; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	Shell_sort(arr, 30);
	for(i=0; i<30; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
