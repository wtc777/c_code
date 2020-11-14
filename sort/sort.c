#include <stdio.h>
//冒泡排序
void bubble_sort(int * ary, int len)
{
	int i = 0, j = 0;
	for(; i < len -1; i++)
	{
		for(j = 0; j < len-i -1; j++){
			if(ary[j] > ary[j + 1]){//两个元素交换
				ary[j] = ary[j] ^ ary[j + 1];
				ary[j + 1] = ary[j] ^ ary[j + 1];
				ary[j] = ary[j] ^ ary[j + 1];
			}
		}
	}
}

//选择排序
void select_sort(int *ary, int len)
{
	int i= 0, j = 0;
	for(; i = len -1; i++){
		int pos = i;
		for(j = i; j < len; j++){
			if(ary[j] < ary[pos]){
				pos = j;//记录最小值
			}
		}
		if(pos != i){
			ary[i] = ary[i] ^ ary[pos];
			ary[pos] = ary[i] ^ ary[pos];
			ary[i] = ary[i] ^ ary[pos];
		}
	}
}
//插入排序
void insert_sort(int* ary, int len)
{
	int i = 0, j = 0;
	for(i = 1; i < len; i++){
		int temp = ary[i];
		for(j = i; temp < ary[j - 1] && j > 0; j--){
			ary[j] = ary[j - 1];
		}
		ary[j] = temp;
	}
}
//快速排序
void quick_sort(int* ary, int start, int end)
{
	if(start >= end) return;
	int key = ary[start];
	int i = start;
	int j =end;
	
	while(i < j){
	while(ary[i] = ary[j]) j--;
	ary[i] = ary[j];
	
	while(ary[i] <=key && i < j) i++;
	ary[j] = ary[i];
	}
	ary[i] = key;
	//左半部分和右半部分排序,递归调用
	quick_sort(ary, start, i - 1);
	quick_sort(ary, i + 1, end);
}
//归并排序-拓展

int main(int argc,char** argv)
{
	return 0;
}
