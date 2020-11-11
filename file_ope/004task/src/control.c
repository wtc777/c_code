#include<stdio.h>

#include"fruit.h"
#include"view.h"
#include"control.h"

void conmain(Fruit p[],int *pidx)
{
	int isRun=1,choice=-1;
	while(isRun)
	{
		viewmain();
		int res=scanf("%d",&choice);
		CLEAR();
		if (res>0&&choice>=0&&choice<6){
			switch(choice){
				case 1:
					insert_fruit(p,pidx);//添加水果信息
					break;
				case 2:
					print_all(p,pidx);//打印所有水果信息
					break;
				case 3:
					condele_fruit(p,pidx);//删除水果信息
					break;
				case 4:
					sort_price(p,pidx);//水果信息排序升序
					break;
				case 5:
					conupdate_fruit(p,pidx);//修改水果信息
					break;
				case 0:
					return ;
			}
			CLEAR();
			}
		}
	}

int file_load(Fruit*p,int *pidx)
{
	FILE *fp=fopen("data.txt","rt");
	if(NULL==fp){
		printf("file open failed");
		return -1;
	}
	if(fscanf(fp,"%d ",pidx)==EOF)
		*pidx=0;
	int i=0;
	while(fscanf(fp,"%d %s %lf",&(p+i)->id,(p+i)->name,&(p+i)->price)!=EOF){
		i++;
	}
	*pidx=i;
	printf("data %d load successful\n",*pidx);
	fclose(fp);
	return 0;
}

int file_save(Fruit*p,int indx)
{
	FILE *fp=fopen("data.txt","wt");
	if(NULL==fp){
		printf("file open failed");
		return -2;
	}
	int i=0;
	fprintf(fp,"%d\n",indx);
	for(i=0;i<indx;i++)
	{
		fprintf(fp,"%d %s %.2f\n",(p+i)->id,(p+i)->name,(p+i)->price);
	}
	printf("data save successfully\n");
	fclose(fp);
	return 0;
}

	
int condele_fruit(Fruit*p,int *pidx)
{
	printf("请输入要删除的水果的id:");
	int id=0;
	int check=scanf("%d",&id);
	if(check<1){
		printf("id input error\n");
		return -5;
	}
	CLEAR();
	delet_fruit(p,pidx,id);
	return 0;
}
int conupdate_fruit(Fruit*p,int *pidx)
{
	printf("请输入要修改的水果的id:");
	int id=0;
	int check=scanf("%d",&id);
	if(check<1){
		printf("id input error\n");
		return -5;
	}
	CLEAR();

	Fruit data={};
	data.id=id;
	printf("请输入水果的名称：");
	mygetstr(data.name,20);
	printf("请输入水果的价格：");
	check=scanf("%lf",&data.price);
	if(check<1){
		printf("price input error\n");
		return -6;
	}
	CLEAR();
	update_fruit(p,pidx,id,&data);
	return 0;
}
