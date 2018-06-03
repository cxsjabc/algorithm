/*
某座城市决定在一块形状为 长为 n、宽为 m 的矩形地面上铺上边长为 a 的正方形地板，并且在这块地基的基础上建造一个大剧院。要求不能弄破地板，并且地板的边要和矩形边平行（地板可以超出矩形地面区域，但是一定要保证矩形地面被地板占满）。问：告诉你n,m和a，至少需要几块地板才能把矩形地面铺满？

输入

一行包括三个正整数n,m,a（1<=n,m,a<=10^9）

输出

输出需要的最少地板数。

样例输入

6 6 4

样例输出

4
*/

#include "common_local.h"

long get_result(long m, long n, long a)
{
	return (m + a - 1) / a * (n + a - 1) / a;
}

int main()
{
	long n, m, a;
	long n1, m1;

	scanf("%ld%ld%ld", &n, &m, &a);
	n1 = n / a * a == n ? n / a : (n / a + 1);
	m1 = m / a * a == m ? m / a : (m / a + 1);
	printf("%ld\n", n1 * m1);	
	PL(get_result(m, n, a));

    return 0;
}
