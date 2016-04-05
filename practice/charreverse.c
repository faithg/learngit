#include<stdio.h>

void Reverse(char *s, int begin, int end)
{
	while(begin < end)
	{
		char c = s[begin];
		s[begin++] = s[end];
		s[end--] = c;
	}
}

void char_reverse(char *s, int m, int n)
{
	Reverse(s,0,n-m-1);
	Reverse(s,n-m,n-1);
	Reverse(s,0,n-1);
}

int main()
{
	char s[13] = "ilovebaofeng";
	printf("%s\n", s);
	char_reverse(s, 7, 12);
	printf("%s\n", s);
	return 0;
}
