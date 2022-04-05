#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void transfer(char a[],int t)
{
	int i;
	for (i = 0; i < t; i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Y')
			a[i] = a[i] + 'b' - 'A';
		else if (a[i] == 'Z')
			a[i] = 'a';
		else if (a[i] >= 'a' && a[i] <= 'x')
			a[i] = a[i] - ('a' - 'C');
		else if (a[i] == 'y' || a[i] == 'z')
			a[i] = a[i] - ('y' - 'A');
	}
}
int main()
{
	int n, i, j;
	scanf("%d", &n);
	char arr[11][90];
	int b[11] = { 0 };
	int count[11] = { 0 };//计算有效字符数
	int num = n;//有效字符串
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		scanf("%s", arr[i]);

	}
	for (i = 0; i < n; i++)
	{
		int tt = strlen(arr[i]);
		for (j = 0; j < strlen(arr[i]); j++)
		{
			if (arr[i][j] != '.')
			{
				count[i]++;
				tt--;
			}

			if ((arr[i][j] == '.' && count[i] == 0) || tt == 0)//如果tt==0，意味着没有'.'
			{
				num--;
				arr[i][0] = '\0';//将无效的字符串首字母改成'\0'以便后续加密
			}
			if (arr[i][j] == '.')
			{
				arr[i][j] = '\0';
				break;
			}
		}
	}
	if (num != 0)
	{
		char c[1000] = "0";
		c[0] = '0' + num;
		for (i = 0; i < n; i++)
		{
			if (b[i] < 10)
			{
				c[1 + 4 * i] = '0';
				c[2 + 4 * i] = '0' + b[i];
			}
			else
			{
				int p = b[i] / 10;
				int q = b[i] % 10;
				c[1 + 4 * i] = '0' + p;
				c[2 + 4 * i] = '0' + q;
			}
			if (count[i] < 10)
			{
				c[3 + 4 * i] = '0';
				c[4 + 4 * i] = '0' + count[i];
			}
			else
			{
				int p = count[i] / 10;
				int q = count[i] % 10;
				c[3 + 4 * i] = '0' + p;
				c[4 + 4 * i] = '0' + q;
			}
		}//已存入1+4n个字符
		for (i = 0; i < n; i++)
		{
			transfer(arr[i], strlen(arr[i]));//替换字母
			strcat(c, arr[i]);

		}
		strcat(c, ".\0");
		printf("%s", c);
	}
	else
	{
		printf("数据无效！");
	}
	return 0;
}