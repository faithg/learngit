/**
 * @file bucket.c
 * @brief Ͱ����
 * @author cui
 * @version 1.0
 * @date 2016-04-11
 */
#include<stdio.h>
#include<stdlib.h>

///1000Ϊ�����������ݵĴ�С��ΧΪ0-999.
int buf[1000] = {0};
void bucket_sort(int* arr, int len)
{
	int i;
	///������arr[]�е�����buf[]��Ӧ���±��Ԫ�ؼ�һ.
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
 * @brief ������.
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
