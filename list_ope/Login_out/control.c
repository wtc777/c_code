#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"List.h"
#include"control.h"
#include"view.h"
 
void conmain(List* pHead)//主函数控制
{
	List* p = NULL;
	int run = 3;
	int type1 = 0;
	while(run){
		viewmain();
		int choice = getchoice();
		switch(choice){
			case 1:
				p = conlogin(pHead);
				break;
			case 2:
				viewtype();
				type1 = getchoice();
				if(type1 == 1){
					conregist(pHead, 1);
				}else if(type1 == 2){
					printf("请登录管理员账号\n");
					p = conlogin(pHead);
					if(p == NULL){
						printf("login error\n");
					}else if (strcmp(p->data.type,"admin") == 0){
						conregist(pHead,2);
					}
				}
				break;
			case 3:
				run-=3;
				break;
		}
	}
}

List* conregist(List* pHead, int type)//注册
{
	userLink user = {};
	printf("请注册\n");
	printf("请输入用户名:");
	mygetstr(user.count,20);
	List* q = findcount(pHead, user.count);
	if(NULL != q){
		printf("用户名重复\n");
		return NULL;
	}
	printf("请输入密码:");
	mygetstr(user.password,20);
	if(type == 1){
		strcpy(user.type,"user");
	}else if(type == 2){
		strcpy(user.type,"admin");
	}
	
	List*pNode = createNode(user);
	insertNode(pHead,pNode);
	printf("regist successfully\n");
	return pNode;
}

List* conlogin(List* pHead)//登录
{
	char count[20] = {};
	char password[20] = {};
	printf("请登录\n");
	printf("请输入用户名:");
	mygetstr(count,20);
	List* q = findcount(pHead,coount);
	if(NULL == q){
		printf("该用户不存在\n");
		return NULL；
	}
	
	printf("请输入密码:");
	mygetstr(password, 20);
	if(0 == strcmp(password, q->data.password)){
		printf("%s login successfully\n",q->data.type);
	}else{
		printf("password is wrong\n");
		return NULL;
	}
	return q;
}
