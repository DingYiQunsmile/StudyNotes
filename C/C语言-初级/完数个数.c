/*
编写程序，求完数。程序运行时输入一个正整数n（n在10到999之间），输出1到n之间的完数（包含n）。
（提示：一个数如果恰好等于它的因子之和，这个数就称为"完数"。假如整数n除以m，
结果是无余数的整数，那么我们称m就是n的因子。需要注意的是，唯有被除数，
除数，商皆为整数，余数为零时，此关系才成立。反过来说，我们称n为m的倍数。）
*/ 

#include <stdio.h>
int main()
{
	int n,i,j,s,d;
	printf("请输入一个正整数 ：");
	scanf("%d",&n);
	if(n < 10 || n > 999) return 0;
	s = 0;
	for(i = 10; i <= n;i ++)
	{
		d = 0;
		for(j = 1;j < i;j ++)
			if(i % j == 0)
				d += j;
		if(d == i)
		{
			s ++;
			printf("完数 ：%d\t",j);
		}
	} 
	printf("完数的个数 ：%d\n",s);
	return 0;
}

