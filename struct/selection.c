#include<stdio.h>

static void swap(int* a, int* b)
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

static void Select_sort(int* arr, int len)
{
	int i,j,min;
	for(i=0; i<len; i++)
	{
		min = i;
		///找到最小值
		for(j=i+1; j<len; j++)
		{
			if(arr[min]>arr[j])
			  min = j;
		}
		
		///交换到有序的序列中
		if(min!=i)
		  swap(&arr[i], &arr[min]);
	}
}

int main()
{
	int arr[10] = {2,1,5,3,12,43,6,5,7,4};
	int i;
	for(i=0; i<10; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	Select_sort(arr, 10);
	for(i=0; i<10; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
