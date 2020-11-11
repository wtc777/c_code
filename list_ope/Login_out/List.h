#ifndef _LIAT_H_
#define _LIAR_H_
#define C 20
#define P 20
#define T 20
//链表节点-值域结构体
typedef struct ListNode
{
	char count[C];
	char password[P];
	char type[T];
}userLink;
//定义链表节点
typedef struct List
{
	userLink data;
	struct List* next;
}List;

void mygetstr(char* p, int l);//字符串输入函数
List* createNode(userLink data);//创建节点-申请堆空间函数
void insertNode(List* pHead, List* pNode);//尾插法插入链表节点
List* findcount(List* pHead, char* couIn);//链表用户名查重
void freeNode(List* pHead);//释放链表堆空间
void bfile_save(List* pHead);//保存链表为二进制文件
void bfile_load(List* pHead);//加载二进制文件生成链表
void bin_to_txt(void);//二进制文件转换为txt文件

#endif
