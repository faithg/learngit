#include<stdio.h>

static void insert_sort(int* arr, int len)
{
	int i,j,k;
	for(i=1; i<len; i++)
	{
		for(j=i-1; j>=0; j--)
		  if(arr[j]<arr[i])
			break;
		if(j!=i-1)///���j=i-1,�Ͳ�����λ.
		{
			int tmp= arr[i];
			for(k=i-1; k>j; k--)
			  arr[k+1] = arr[k];
			arr[k+1] = tmp;///��Ϊforѭ�������k����1,����a[k+1].
		}
	}
}

int main()
{
	int arr[10] = {2,1,3,4,21,6,21,12,7,9};
	int i;
	for(i=0; i<10; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	insert_sort(arr, 10);
	for(i=0; i<10; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
