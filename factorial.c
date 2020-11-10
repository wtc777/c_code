//测试函数的递归调用-阶乘
#include <stdio.h>
int fact(int value)
{
	if(value == 1) return 1;
	return value * fact(value - 1);
}
int main(int argc, char** argv)
{
	printf("%d\n",fact(10));
	return 0;
}
