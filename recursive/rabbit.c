//兔子出生两个月后，就有繁殖能力，一对兔子每个月能生出一对小兔子，如果所有兔子都不死，
//那么一年以后可以繁殖多少对兔子
#include <stdio.h>
//兔子计算函数
int rabbit(int n)
{
	if(n == 1 || n == 2){
		return 1;
	}else{
		return rabbit(n - 1) + rabbit(n - 2);
	}
}

int main(int argc, char** argv)
{
	int n = 12;
	int res = rabbit(n);
	printf("经过12个月，一共有%d只兔子\n",res);
	return 0;
}
