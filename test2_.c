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
	int** a; int** c;
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
		c = (int**)malloc(sizeof(int*) * m);//为二维数组分配m行
		for (i = 0; i < m; i++) //为每行分配n列
		{
			c[i] = (int*)malloc(sizeof(int) * n);
		}
		int l = 0, r = n - 1, t = 0, b = m - 1, x = 1;
		int* val;
		val = (int*)malloc(sizeof(int) * m * n+1);//将矩阵按顺时针存到一个数组里，调整数组元素后再顺序赋值给c数组里
		while (1)
		{
			// left to right.
			for (int i = l; i <= r; i++)	//从左到右，i就等于左，i<=右
			{
				val[x++] = a[t][i]; //在最上一行输出，变化的是列，所以列标=i
			}

			if (++t > b) break;	//下面要走的是从上到下，所以先判断上边界+1是否比下边界大，如果大说明已经结束。
			// top to bottom.
			for (int i = t; i <= b; i++)	//从上到下，i就等于上，i<=下
			{
				val[x++] = a[i][r]; //在最右一列输出，变化的是行，所以行标=i
			}

			if (l > --r) break;	//下面要走的是从右到左，所以先判断左边界是否比右边界-1大，如果大说明已经结束。
			// right to left.
			for (int i = r; i >= l; i--)	//从右到左，i就等于右，i>=左
			{
				val[x++] = a[b][i];	//在最后一行输出,变化的是列标,所以列表=i
			}

			if (t > --b) break;	//下面要走的是从下到上，所以先判断上边界是否比下边界-1大，如果大说明已经结束。
			// bottom to top.
			for (int i = b; i >= t; i--)	//从下到上，i就等于下，i>=上
			{
				val[x++] = a[i][l];	//在最左一列输出,变化的是行标,所以行表=i
			}
			if (++l > r) break;	 //下面要走的是从左到右，所以先判断左边界+1是否比右边界大，如果大说明已经结束。
		}
		val[0] = val[m * n];
		x = 0; l = 0; r = n - 1; t = 0; b = m - 1;
		while (1)//赋值给c数组
		{
			for (int i = l; i <= r; i++)	
			{
				c[t][i]=val[x++]; 
			}
			if (++t > b) break;	
			for (int i = t; i <= b; i++)	
			{
				c[i][r]=val[x++]; 
			}
			if (l > --r) break;	
			
			for (int i = r; i >= l; i--)	
			{
				c[b][i]=val[x++] ;	
			}
			if (t > --b) break;	
			
			for (int i = b; i >= t; i--)	
			{
				c[i][l]=val[x++]  ;	
			}
			if (++l > r) break;	
		}
		for (i = 0; i < m; i++)//输出矩阵
		{
			for (j = 0; j < n; j++)
			{
				printf("%d ", c[i][j]);//
			}
			printf("\n");
		}
		for (i = 0; i < m; ++i) {
			free(a[i]);
			free(c[i]);
		}
		free(a);
		free(c);
	return 0;
}

