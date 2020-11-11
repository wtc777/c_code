#include"fruit.h"
#include<stdio.h>
#include<string.h>

void mygetstr(char*p,int l)
{
	if(NULL==p)
		return;
	fgets(p,l,stdin);
	int len=strlen(p);
	if(len>0&&p[len-1]=='\n'){
		p[len-1]='\0';
	}else{
		CLEAR();
	}
}

int insert_fruit(Fruit*p,int *pidx)
{
	if(*pidx>=M){
		printf("空间已满，插入水果信息失败\n");
		return -1;
	}
	(p+*pidx)->id=*pidx;
	printf("请输入水果名称：");
	mygetstr((p+*pidx)->name,20);
	printf("请输入水果的价格：");
	int check=scanf("%lf",&(p+*pidx)->price);
	if(check<1){
		printf("price input error");
		return -2;
	}
	CLEAR();
	(*pidx)++;
	printf("insert ok\n");
	return 0;
}

void print_all(Fruit *p,int *pidx)
{
	int i=0;
	printf("序号id\t水果名称\t价格\t\n");
	for(i=0;i<*pidx;i++)
	{
		printf("%d\t",(p+i)->id);
		printf("%s\t\t",(p+i)->name);
		printf("%.3f\n",(p+i)->price);
	}
	printf("output ok\n");
}

int find_fruit(Fruit*p,int *pidx,int id)
{
	int i=0;
	for(;i<*pidx;i++)
	{
		if((p+i)->id==id)
			return i;
	}
	printf("find fruit message failed\n");
	return -3;
}

int delet_fruit(Fruit*p,int *pidx,int id)
{
	int pos=find_fruit(p,pidx,id);
	if(pos==-3){
		return -3;
	}

	int i=pos;
	for(;i<*pidx-1;i++)
	{
		*(p+i)=*(p+i+1);
	}
	memset((p+i),0,sizeof(Fruit));
	(*pidx)--;
	printf("delete ok\n");
	return 0;
}
int update_fruit(Fruit*p,int *pidx,int id,Fruit*data)
{
	int pos=find_fruit(p,pidx,id);
	if(pos==-3){
		return -3;
	}

	*(p+pos)=*data;
	return 0;
	printf("update ok\n");
}
void sort_price(Fruit*p,int *pidx)
{
	int i=0,j=0;
	for(i=0;i<*pidx-1;i++)
	{
		for(j=0;j<*pidx-i-1;j++)
		{
			if((p+j)->price>(p+j+1)->price){
				swap(p+j,p+j+1);
			}
		}
	}
	printf("sort ok\n");
}

void swap(Fruit*a,Fruit*b)
{
	Fruit temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
