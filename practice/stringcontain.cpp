/**
 * @file stringcontain.cpp
 * @brief 测试字符串包含程序
 * @author cui
 * @version 1.0
 * @date 2016-04-05
 */
#include<stdio.h>
#include<string.h>

/**
 * @brief b是否在a里,26位表示26个大写字母,然后
 * 再检测b中的字符串是否在hash中.
 *
 * @param a 字符串
 * @param b 字符串
 * 
 * @return 包含返回true;不包含返回false. 
 * */
bool StringContain(char *a, char *b)
{
	int hash = 0;
	int i;
	for(i=0; i<strlen(a); i++)
	{
		hash |= (1 << (a[i] - 'A'));
	}
	for(i=0; i<strlen(b); i++)
	{
		if((hash & (1 << (b[i] - 'A'))) == 0)
		  return false;
	}
	return true;
}

int main()
{
	char a[10] = "ASDFGHJKL";
	char b[5] = "ASHJ";
	char c[5] = "ASZC";
	bool b1, b2;
	b1 = StringContain(a,b);
	b2 = StringContain(a,c);
	printf("b1 = %d\n", b1);
	printf("b2 = %d\n", b2);
	return 0;
}

