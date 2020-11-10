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
	//提取文件中字符串
	char str[100] = {};
	fgets(str, 100, fp);
	int i, j;
	if(strlen(str) < 3){
		printf("文件中字符个数不足\n");
		return -2;
	}
	//比较abc个数
	for(i = 0, j = 0; i < strlen(str) -2; i++){
		if(str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c'){
			j++;
		}
	}
	printf("abc的个数：%d\n",j);
	return 0;
}
