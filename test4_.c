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
	int i,num=n-m,en=0;//num���ʼûռ��ȡ��������
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
				num--;//ǰ��ճ���λ���ɺ����Ŷӵ��˽��ϣ�������1
			}
			if (a[i] ==0)
				en++;//��һ�����ӳ���û������
		}//һ���ȥ
		time++;
		if (en == m)
			break;
	}
	printf("%d\n", time);
	free(a);
	return 0;
}