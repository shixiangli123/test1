#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int time = 0;
	int m, n;
	scanf("%d%d", &m, &n);
	printf("%d %d\n", m, n);
	int* a;
	a = (int*)malloc(sizeof(int) * m);
	int i,num=n-m,en=0;//num是最开始没占到取件机的人
	if (m < n)//人比机子多
	{
		for (i = 0; i < m; i++)
		{
			scanf("%d", &a[i]);
		}
		while (1)
		{
			for (i = 0; i < m; i++)
			{
				a[i]--;
				if (a[i] == 0 && num > 0)
				{
					scanf("%d", &a[i]);
					num--;//前面空出的位置由后面排队的人接上，人数少1
				}
				if (a[i] == 0)
					en++;//有一个机子彻底没人排了
			}//一秒过去
			time++;
			if (en == m)
				break;
		}
		printf("%d\n", time);
	}
	else//每人都有机子
	{
		int* c;
		c = (int*)malloc(sizeof(int) * n);//n个人的快递数分别放进数组里，求出最大值
		for (i = 0; i < n; i++)
		{
			scanf("%d", &c[i]);
		}
		int x = c[0];
		for (i = 0; i < n - 1; i++)
		{
			x = x > c[i + 1] ? x : c[i + 1];
		}
		printf("%d\n", x);
	}
	
	free(a);
	return 0;
}
