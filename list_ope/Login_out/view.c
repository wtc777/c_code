#include <stdio.h>
#include <stdlib.h>
#define CLEAR() while(getchar() != '\n')
void viewmain(void)
{
	printf("登录界面\n");
	printf("1.登录\n");
	printf("2.注册\n");
	printf("3.退出\n");
}

void viewtype(void)
{
	printf("请选择账户类型\n");
	printf("1.普通用户\n");
	printf("2.管理员\n");
}

int getchoice(void)
{
	int choice = 0;
	printf("请输入你的选择\n");
	int res = scanf("%d",&choice);
	CLEAR();
	if(res < 1){
		printf("input error\n");
		return -1;
	}
	return choice;
}
