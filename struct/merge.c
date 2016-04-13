#include<stdio.h>
#include<stdlib.h>

#define MAX ~(1<<31)

static void merge(int* arr, int p, int q, int r)
{
	int i,j,k;
	int n1,n2;
	n1 = q-p+1;
	n2 = r-q;
	int *L = (int*)malloc((n1+1)*sizeof(int));
	int *R = (int*)malloc((n2+1)*sizeof(int));
	for(i=0; i<n1; i++)
		L[i] = arr[p+i];
	for(j=0; j<n2; j++)
		R[j] = arr[q+j+1];
	L[n1] = MAX;
	R[n2] = MAX;
	i = 0;
	j = 0;
	for(k=p; k<r+1; k++)
	{
		if(L[i]<R[j])
		  arr[k] = L[i++];
		else
		  arr[k] = R[j++];
	}
	
	
	free(L);
	free(R);
}

static void merge_sort(int* arr, int p, int r)
{
	if(p<r)
	{
		int q = (p+r)/2;
		merge_sort(arr, p, q);
		merge_sort(arr, q+1, r);
		merge(arr, p, q, r);
	}
}

int main()
{
	int arr[10] = {4,2,9,2,12,6,7,3,1,57};
	int i;
	int len = 10;
	merge_sort(arr, 0, len-1);
//	merge(arr, 0, len-1, len);
	for(i=0; i<len; i++)
	  printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
