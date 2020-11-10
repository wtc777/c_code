//文件的复制
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{	
	if(3 != argc){
		perror("argc error!\n");
		return -1;
	}
	printf("%s,%s\n",argv[1],argv[2]);
	fflush(stdout);
	//源文件打开 只读方式
	FILE* fp1 = fopen(argv[1],"rt");
	if(NULL == fp1){
		printf("file %s open failed\n",argv[1]);
		return -2;
	}
	//目标文件打开 只写方式
	FILE* fp2 = fopen(argv[2],"wt");
	if(NULL == fp2){
		printf("file %s open failed\n",argv[2]);
		return -2;
	}
	
	char ch = '\0';
	while((ch = fgetc(fp1)) != EOF){
		fputc(ch, fp2);
	}
	//关闭文件
	fclose(fp1);
	fclose(fp2);
	
	return 0;
}
