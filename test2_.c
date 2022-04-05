#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand((unsigned int)time(NULL));
	int m = rand() % 5 + 3;//生成行和列
	int n = rand() % 5 + 3;
	printf("%d %d\n", m, n);
	int** a; int** b;
	int i, j;
	a = (int**)malloc(sizeof(int*) * m);//为二维数组分配m行
	for (i = 0; i < m; i++) //为每行分配n列
		{
			a[i] = (int*)malloc(sizeof(int) * n);
		}
	printf("原矩阵为：\n");
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				a[i][j] = rand()%9+1;
				printf("%d ", a[i][j]);//初始化
			}
			printf("\n");
		}
		printf("移动后矩阵为：\n");
		//暂时不会
		
		for (i = 0; i < m; i++)//输出矩阵
		{
			for (j = 0; j < n-1; j++)
			{
				printf("%d ", b[i][j]);//
			}
			printf("\n");
		}
		for (i = 0; i < m; ++i) {
			free(a[i]);
			free(b[i]);
		}
		free(a);
		free(b);
	return 0;
}


