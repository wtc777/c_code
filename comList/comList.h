#ifndef COMLIST_H_
#define COMLIST_H_
typedef union com{
	int size;//数据类型的大小
	void* data;//数值域的指针
}u_com;

typedef struct comList{
	u_com uc;//联合部分-数值域
	struct comList* next;//下一节点的指针
	struct comList* prev;//上一节点的指针
}cList;

cList* create_link(int size);//创建链表；并传递链表节点数值域的大小
int insert_node(cList* head, void* data);//插入节点
void delete_node(cList* head, void* data, int(*cmp)(const void*, const void*));//删除节点
int modify_node(cList* head, void * old, void* data, int(*cmp)(const void*, const void*));//修改节点数值域的值
void print_link(cList* head, void(*print)(const void*));//遍历打印
#endif