#include <stdio.h>

union com{
	int x;
	char uc[2];
}c;

int main(void)
{
	//使用联合体测试大小端字节序
	//大端：数据高位在地址低位;小端：数据地位存放在地址低位
	c.x = 0x1234;
	printf("uc[0]:0x%x;uc[1]:0x%x\n",c.uc[0],c.uc[1]);

	//使用指针方式测试
	int a = 0x5678;
	char*p = (char*)&a;
	printf("p:0x%x;p+1:0x%x\n",*p,*(p + 1));

	return 0;
}
