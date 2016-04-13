#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b)
{
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

void radix_sort(int* arr, int len)
{
	int i,j;
	int min;
	int flag;
	int base = 1;
	while(1)
	{
		flag = 0;
		base = base*10;
	for(i=0; i<len; i++)
	{
		min = i;
	  for(j=i+1; j<len; j++)
	  {
		if(arr[min]%base>arr[j]%base)
		  min = j;
		else
		  min = min;
	  }
	  if(min!=i)
	  {
		swap(&arr[i], &arr[min]);
		flag = 1;
	  }
	}
	if(flag==0)
	  break;
	}
}

int main()
{
	int i;
	int arr[10] = {21,15,62,81,60,99,3,0,44,76};
	for(i=0; i<10; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	radix_sort(arr, 10);
	for(i=0; i<10; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
