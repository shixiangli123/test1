#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int jisuan(int n)
{


}
int main()
{
	int n,count=0;
	scanf("%d", &n);
	int m = n;
	while(1)
	{
		if (n % 2 == 0)
		{
			n = n / 2;
			count++;
		}
		else
		{
			n = n - 1;
			count++;
		}
		if (n == 1)
			break;
	}
	printf("%d\n", count);
	while (1)
	{
		if (m % 2 == 0)
		{
			m = m / 2;
			printf("^");
		}
		else
		{
			m = m - 1;
			printf("-");
		}
		if (m == 1)
			break;
	}





}