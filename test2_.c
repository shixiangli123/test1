#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand((unsigned int)time(NULL));
	int m = rand() % 5 + 3;//�����к���
	int n = rand() % 5 + 3;
	printf("%d %d\n", m, n);
	int** a; int** b;
	int i, j;
	a = (int**)malloc(sizeof(int*) * m);//Ϊ��ά�������m��
	for (i = 0; i < m; i++) //Ϊÿ�з���n��
		{
			a[i] = (int*)malloc(sizeof(int) * n);
		}
	printf("ԭ����Ϊ��\n");
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				a[i][j] = rand()%9+1;
				printf("%d ", a[i][j]);//��ʼ��
			}
			printf("\n");
		}
		printf("�ƶ������Ϊ��\n");
		//��ʱ����
		
		for (i = 0; i < m; i++)//�������
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


