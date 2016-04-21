/**
 * @file kmp.c
 * @brief kmp字符匹配算法
 * @author cui
 * @version 1.0
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
	///next[]数组的第一个元素必为0
	next[0] = 0;
	///从第二个字符开始遍历,找到前缀和后缀最大相同字符串长度
	for(i=1,k=0; i<strlen(D); i++)
	{
		///k为next[]数组值,当k大于0,说明之前有匹配的字符,
		///再检测下一个字符是否相同,如果不同更新k值,直到k=0,
		///若无相等的字符,next[i]=0.
		while(k>0 && D[i]!=D[k])
		  ///因为在第k-1字符处有next[k-1]个相同的字符
		  ///所以移动next[k-1]个位置.
		  k = next[k-1];
		///相同k在之前的基础上增加1
		if(D[i]==D[k])
		  k++;

		next[i] = k;
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
	int i,j = 0;
	Next(next, D);
	int slen = strlen(S);
	int dlen = strlen(D);
	printf("****%s\n", D);
	for(i=0; i<slen; i++)
	{
		while(j>0 && S[i]!=D[j])
		{
			j = next[j-1];
		}
		if(S[i]==D[j])
		{
			j++;
		}
		///如果j==dlen说明有匹配的字符串
		if(j==dlen)
		{
			printf("移动到第%d位.\n", i-j+1);
		}
	}
}

int main()
{
	char S[] = "bbc abcdab abcdabcdabde";
	char D[] = "abcdabd";
	int next[7] = {0};
	Kmp(next, S, D);
	int i;
	for(i=0; i<7; i++)
	  printf("%d ", next[i]);
	printf("\n");
	return 0;
}
