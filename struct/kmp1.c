/**
 * @file kmp.c
 * @brief kmp字符匹配算法
 * @author cui
 * @version 1.1
 * @date 2016-04-13
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief 部分匹配表即next[]数组
 *
 * @param next
 * @param D待匹配字符串
 */
void Next(int* next, char* D)
{
	int i,k;
	///next[]数组的第一个元素为-1
	next[0] = -1;
	k = -1;
	i = 0;
	///从第二个字符开始遍历,找到前缀和后缀最大相同字符串长度
	while(i<strlen(D))
	{
		if(k==-1 || D[i]==D[k])
		{
			++i;
			++k;
			next[i] = k;
		}
		else
		{
			k = next[k];
		}
	}
}

/**
 * @brief 匹配字符的算法
 *
 * @param next 数组
 * @param S 源字符串
 * @param D 待匹配字符串
 */
void Kmp(int* next, char* S, char* D)
{
	int i,j;
	int slen = strlen(S);
	int dlen = strlen(D);
	Next(next, D);
	///D为指针,如果不为指针打印的为空字符,另一个程序就能打印成功,不知道为什么
	printf("------%s\n", D);
	i = 0;
	j = 0;
	while(i<slen && j<dlen)
	{
		if(j==-1 || S[i]==D[j])
		{
			j++;
			i++;
		}
		else
		{
			j = next[j];
		}
	
	}
			printf("j=%d\n", j);
		///如果j==dlen说明有匹配的字符串
		if(j==dlen)
		{
			printf("移动到第%d位.\n", i-j);
		}
}

int main()
{
	char *S = "bbc abcdab abcdabcdabde";
	///D为指针
	char *D = "abcdabd";
	int next[7] = {0};
	Kmp(next, S, D);
	int i;
	for(i=0; i<7; i++)
	  printf("%d ", next[i]);
	printf("\n");
	return 0;
}
