#include <stdio.h>

//二分法/折半法--必须保证序列是有序的
int find_binary_search(int *ary, int start, int end, int findValue)
{
	if(start > end) return -1;
	static int count = 0;
	printf("这是第%d次查找...\n"，++count);
	int mid - (start + end) / 2;
	if(findValue > ary[mid]){
		return find_binary_search(ary, mid + 1, end, findValue）；
	}else if)findValue < ary[mid]{
		return find_binary_search(ary, start, mid - 1, findValue);
	}else{
		return mid;
	}
}
//顺序查找
//快查找
int main(int argc, char** argv)
{
	return 0;
}
