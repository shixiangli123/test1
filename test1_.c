#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int prime(int m)//判断是否为素数
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
    //case 1如果a是一个大于等于4的偶数，必可分解为两个素数之和
    //case 2如果a是一个大于等于7的奇数，必可以分解为三个素数之和,a=3+(a-3),a-3是一个偶数归到case 1
    //case 3那么只要将5这个特例单独写成2+3，其余的情况便可归结为a为奇数和偶数问题，而5=2+3可归到case 1
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