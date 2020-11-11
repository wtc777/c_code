#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"fruit.h"
#include"control.h"

int main(void)
{
	Fruit*p=(Fruit*)malloc(sizeof(Fruit)*M);
	int index=0;
	file_load(p,&index);
	//Fruit arr[M]={};
	//Fruit *p=arr;
	conmain(p,&index);
	file_save(p,index);
	free(p);
	return 0;
}
