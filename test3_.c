#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int jisuan(int n)//函数作用：计算最少步数，使用递归思想，只考虑下一步，是否除2
{
	if(n==1)
		return 0;
	if (n % 2 == 0)
	{
		return 1 + jisuan(n / 2);
	}
	int x = jisuan(n + 1);
	int y = jisuan(n - 1);
	if (x > y)
	{
		return y + 1;
	}
	else
	{
		return x + 1;
	}
}
int proce(int n,int g)//函数作用：这里主要负责打印运算符
{
	if (n == 1)
		return 0;
	if (n % 2 == 0)
	{
		if(g==1)//g用来判断是否打印
			printf("^");
		
		return (1 + proce(n / 2,g));
	}
	int x = proce(n + 1,0);//不打印
	int y = proce(n - 1,0);
	if (x > y)
	{
		if(g==1)
		printf("-");
		
		return proce(n - 1, g) + 1;
	}
	else 
	{
		if(g==1)
		printf("+");
		return  proce(n + 1, g) + 1;
	}
}
int main()
{
	int n,count;
	scanf("%d", &n);
	count=jisuan(n);
	printf("%d\n", count);
	proce(n,1);
}
