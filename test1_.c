#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int prime(int m)//�ж��Ƿ�Ϊ����
{
    int i = 0;
    for (i = 2; i <= sqrt(m); i++)
    {
        if (m % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int a, i,b;
    scanf("%d", &a);
    //case 1���a��һ�����ڵ���4��ż�����ؿɷֽ�Ϊ��������֮��
    //case 2���a��һ�����ڵ���7���������ؿ��Էֽ�Ϊ��������֮��,a=3+(a-3),a-3��һ��ż���鵽case 1
    //case 3��ôֻҪ��5�����������д��2+3������������ɹ��ΪaΪ������ż�����⣬��5=2+3�ɹ鵽case 1
    if (a % 2 == 0 || a == 5)
    {
        for (i = 2; i < a; i++)
        {
            if (prime(i) && prime(a - i))
            {
                printf("%d = %d + %d", a, i, a - i);
                break;
            }
        }
    }
    else
    {
        b = a - 3;
        for (i = 2; i < b; i++)
        {
            if (prime(i) && prime(b - i))
            {
                printf("%d = 3 + %d + %d", a, i, b - i);
                break;
            }
        }
    }
    return 0;
}