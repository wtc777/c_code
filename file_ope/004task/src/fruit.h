#ifndef __fruit_H__
#define __fruit_H__
#define CLEAR() while(getchar()!='\n')
#define M 100
typedef struct Fruit{
	int id;
	char name[20];
	double price;
}Fruit;

void mygetstr(char*p,int l);//字符串输入函数
int insert_fruit(Fruit*p,int *pidx);//水果信息插入函数
int find_fruit(Fruit*p,int *pidx,int id);//水果信息查找函数
void print_all(Fruit *p,int *pidx);//打印所有水果信息函数
int delet_fruit(Fruit*p,int *pidx,int id);//删除水果信息
int update_fruit(Fruit*p,int *pidx,int id,Fruit*data);//更新水果信息
void sort_price(Fruit*p,int *pidx);//水果按照价格排序
void swap(Fruit*a,Fruit*b);//交换函数

#endif
