#include <stdio.h>
#include <string.h>

//获取字符串长度
int my_strlen(char* s)
{
	int size = 0;
	while(*s++){
		size++;
	}
	return size;
}
//字符串拷贝函数
char* my_strcpy(char* dest, char* src)
{
	char * _dest = dest;
	for(; *dest = *src; dest++,src++);
	return _dest;
}
//字符串连接函数
char* my_strcat(char* dest, char* src)
{
	char* _dest = dest;
	//找尾
	while(*dest){
		dest++;
	}
	//连接字符串
	for(; *dest = *src; src++);
	return _dest;
}
//字符串比较函数
int my_strcmp(const char* s1,const char* s2)
{
	for(;*s1 || *s2; s1++, s2++){
		if(*s1 != *s2){
			return *s1 - *s2;
		}
	}
	return 0;
}