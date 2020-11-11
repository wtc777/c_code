#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CLEAR() while(getchar()!='\n')

typedef struct Stu
{
	int id;
	char name[20];
	float result;
}Stu;

void mygetstr(char*p,int l);
int bfile_load(Stu*p,int *pidx);
int bfile_save(Stu*p,int *pidx);
int print_all(Stu*p,int index);
int insert(Stu*p,int*pidx);
int bin_to_txt(void);


int main(void)
{
	Stu*p=(Stu*)malloc(sizeof(Stu)*3);
	int index=0;
	bfile_load(p,&index);
	print_all(p,index);
	insert(p,&index);
	print_all(p,index);
	bfile_save(p,&index);
	bin_to_txt();
	free(p);
	return 0;
}

void mygetstr(char*p,int l)
{
	if(NULL==p){
		printf("point is NULL\n");
		return ;
	}
	fgets(p,20,stdin);
	int len=strlen(p);
	if(len>0&&p[len-1]=='\n'){
		p[len-1]='\0';
	}else{
		CLEAR();
	}
}
int insert(Stu*p,int*pidx)
{
	if(NULL==p){
		printf("point is NULL\n");
		return -1;
	}
	if(*pidx>2){
		printf("空间已满，插入学生成绩失败\n");
		return -2;
	}
	(p+*pidx)->id=(*pidx)+1;
	printf("请输入学生姓名:");
	mygetstr((p+*pidx)->name,20);
	printf("请输入成绩:");
	int res=scanf("%f",&(p+*pidx)->result);
	if(res<1){
		printf("input error\n");
		return -4;
	}
	CLEAR();
	printf("insert ok\n");
	(*pidx)++;
	return 0;
	
}

int print_all(Stu*p,int index)
{
	int i=0;
	printf("ID\t姓名\t成绩\n");
	for(;i<index;i++)
	{
		printf("%d\t%s\t%.2f\n",(p+i)->id,(p+i)->name,(p+i)->result);
	}
	printf("output ok\n");
	return 0;
}

int bfile_load(Stu*p,int *pidx)
{
	if(NULL==p){
		printf("point is NULL\n");
		return -1;
	}
	FILE*fp=fopen("stu.bin","rb");
	if(NULL==fp){
		printf("bfile open failed\n");
		return -5;
	}
	int i=0;
	while(fread(p+i,sizeof(Stu),1,fp)){
		i++;
	}
	*pidx=i;
	printf("data load successfully\n");
	fclose(fp);
	return 0;	
}

int bfile_save(Stu*p,int* pidx)
{
	if(NULL==p){
		printf("point is NULL\n");
		return -1;
	}
	FILE*fp=fopen("stu.bin","wb");
	if(NULL==fp){
		printf("bfile open failed\n");
		return -5;
	}
	//fwrite(pidx,sizeof(int),1,fp);
	fwrite(p,sizeof(Stu),*pidx,fp);
	fclose(fp);
	return 0;
}

int bin_to_txt(void)
{
	FILE*fpb=fopen("stu.bin","rb");
	if(NULL==fpb){
		printf("bin file open failed\n");
		return -6;
	}
	FILE*fpt=fopen("stu.txt","wt");
	if(NULL==fpt){
		printf("txt file open failed\n");
		return -6;
	}
	Stu temp={};
	while(fread(&temp,sizeof(Stu),1,fpb)){
		fprintf(fpt,"%d %s %f\n",temp.id,temp.name,temp.result);
	}
	printf("bin to txt successfully\n");
	return 0;
}
