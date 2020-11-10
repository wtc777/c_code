#include <stdio.h>
#include <string.h>

int main(void)
{
	//只读方式打开文件
	FILE* fp = fopen("text.txt","rt");
	if(NULL == fp){
		perror("file open failed\n");
		return -1;
	}
	//提取文件中的数字
	char str[100] = {};
	fgets(str,100,fp);
	int i = 0;
	for(; i < strlen(str); i++){
		if(str[i] > '0' && str[i] < '9'){
			printf("%c ", str[i]);
		}
	}
	putchar('\n');
	//关闭文件
	fclose(fp);
	return 0;
}
