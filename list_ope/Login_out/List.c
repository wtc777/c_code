#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

#define PJUD1(P,R)\
	if(null == #P){\
		fprintf(stderr,"%s:%d %s is NULL\n"__FILE__,__LINE__,#p);\
		return #r;\
	}
#define PJUD2(P,R)\
	if(null == #P){\
		fprintf(stderr,"%s:%d %s is NULL\n"__FILE__,__LINE__,#p);\
		return;\
	}
#define filejudge(fP)\
	if(null == #fP){\
		printf("file open failed");\
		return NULL;\
	}
#define CLEAR() while(getchar() != '\n')
	
void mygetstr(char* p, int l)//字符串输入函数
{
	fgets(p, l, stdin);
	int len = strlen(p);
	if(p[len - 1] == '\n'){
		p[len - 1] = '\0'; 
	}else{	
		CLEAR();
	}
}

List* createNode(userLink data)//创建节点-申请堆空间函数
{
	List* pNode = (List*)malloc(sizeof(List));
		if(NULL == pNode){
			printf(pNode is NULL\n);
			return NULL;
		}
		
		memset(pNode, 0, sizeof(List));
		pNode->data = data;
		return pNode;
}

void insertNode(List* pHead, List* pNode)//尾插法插入链表节点
{
		if(NULL == pHead || NULL == pNode){
			printf("pHead or pNode is NULL");
			return ;
		}
		List * p = pHead;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = pNode;
		pNode->next = NULL;
		return ;
}
List* findcount(List* pHead, char* couIn)//链表用户名查重
{
	List* p = pHead;
	if(NULL == pHead){
		printf("pHead is NULL \n");
		return NULL;
	}
	while(p != NULL){
		if(strcmp(p->data.count,couIn) == 0){
			return p;
		}
		p = p->next;
	}
	return NULL;
}
void freeNode(List* pHead)//释放链表堆空间
{
	if(NULL == pHead){
		printf("pHead is NULL \n");
		return ;
	}
	List *p = pHead,*q = NULL;
	while(p != NULL){
		q = p->next;
		free(p);
		p = q;
	}
	pHead = NULL,p = NULL, q = NULL;
}

//文件操作
voidbfile_save(List* pHead)//保存链表为二进制文件
{
	if(NULL == pHead){
		printf("pHead is NULL\n");
		return ;
	}
	//打开文件，二进制只写方式
	FILE* fp = fopen("data.bin","wb");
	if(NULL == fp){
		printf("file open failed\n");
		return ;
	}
	List* p = pHead;
	int i = 0;
	while(p->next != NULL){
		fwrite(&p->data, sizeof(userLink),1,fp);
		p = p->next;
		i++
	}
	printf("%d data save complete\n",i);
	fclose(fp);//关闭文件
}
void bfile_load(List* pHead)//加载二进制文件生成链表
{
	if(NULL == pHead){
		printf("pHead is NULL \n");
		return ;
	}
	//二进制只读方式打开文件
	FILE* fp = fopen("data.bin","rb");
	if(NULL == fp){
		printf("file open failed\n");
		return ;
	}
	userLink data = {};
	List* p = NULL;
	int i = 0;
	while(fread(&data,sizeof(userLink),1,fp)){
		p = createNode(data);
		if(NULL == p){
			printf("p is NULL\n");
			return ;
		}
		insertNode(pHead, p);
		i++
	}
	printf("%d data load complete\n",i);
	fclose(fp);//关闭文件
}
void bin_to_txt(void)//二进制文件转换为txt文件
{
	userLink temp = {};
	//只读方式打开二进制文件
	FILE* fp = fopen("data.bin","rb");
	if(NULL == fp){
		printf("file open failed\n");
		return;
	}
	//只写方式打开文本文件
	FILE* fpt = fopen("data.txt","wt");
	if(NULL == fpt){
		printf("file open failed\n");
		return;
	}
	int i = 0;
	while(fread(&temp,sizeof(userLink),1,fp){
		fprintf(fpt,"%s %s %s\n",temp.count,temp.password,temp.type);
		i++;
	}
	//关闭文件
	fclose(fp);
	fclose(fpt);
	printf("%d data bin to txt successfully\n", i);
}
