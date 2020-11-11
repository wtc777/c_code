#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"List.h"
#include"control.h"
#include"view.h"

int main(void)
{
	List *pHead = (List*)malloc(sizeof(List));
	if(NULL == pHead){
		printf("malloc is failed\n");
		return -1;
	}
	bfile_load(pHead);//加载二进制文件
	
	strcpy(pHead->data.count,"admin");
	strcpy(pHead->data.password,"123456");
	strcpy(pHead->data.type,"admin");
	
	conmain(pHead);//主函数控制-交互主界面调用
	
	bfile_save(pHead);
	bin_to_txt();
	freeNode(pHead);
	return 0;
}