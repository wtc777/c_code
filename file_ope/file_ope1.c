#include <string.h>
#include <stdio.h>
int main(void)
{
	//打开文件，只写方式
	FILE* fp = fopen("text.txt","wt");
	if(NULL == fp){
		perror("file open failed\n");
		return -1;
	}
	
	//提示输入字符串
	printf("请输入字符串");
	char str1[100] = {};
	fgets(str1,100,stdin);
	if(str1[strlen(str1) -1] != '\n'){
		str1[strlen(str1) - 1] = '\0';
	}else{
		while(getchar() != '\n');
	}
	fprintf(fp, "%s",str1);
	fclose(fp);

	//只读方式打开文件
	fp = fopen("text.txt","rt");
	if(NULL == fp){
		perror("file open failed\n");
		return -1;
	}
	
	//将文件中的字符串提取到内存字符数组中
	char str2[100] = {};
	fgets(str2, 100, fp);
	printf("提取到的字符串入下:");
	puts(str2);
	int i = 0, j = 0;
	for(i = 0; i < strlen(str2); i++){
		if(' ' == str2[i]){
			j++;
		}
	}
	j++;
	printf("单词个数:%d\n",j);
	fclose(fp);
	return 0;
}
