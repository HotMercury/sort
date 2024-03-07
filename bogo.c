/*
 * worst bigO(∞)
 * best bigO(1)
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y)\
	int tmp = x;\
	x = y;\
	y = tmp;

typedef enum{false,true} bool;

bool check_is_sort(void*, int);
void shuffle(void*, int);
void bogosort(void*, int);
void printArray(void*, int);

int record = 0;

int main(){
	int a[] = {1,3,5,5,376,2};
	int size = sizeof(a) / sizeof(a[0]);
	bogosort(a,size);
	printf("total round : %d\n", record);
	printf("Sorted array : \n");
	printArray(a,size);	
	return 0;
}


bool check_is_sort(void* p, int num){
	int* arr = (int*)p;
	while(--num){
		if(arr[num] < arr[num-1]){
			return false;
		}
	}
	return true;
}


void shuffle(void* p,int num){
	srand( time(NULL) );
	int* arr = (int*)p;
	for(int i = 0; i < num; i++){
		int key = rand() % num;
		SWAP( arr[i], arr[key] );
	}
}

void bogosort(void* p, int num){
	while(!check_is_sort(p,num)){
		record++;
		shuffle(p,num);
	}
}

void printArray(void *p, int num){
	int* arr = (int*)p;
	for(int i = 0; i < num; i++){
		printf(" %d ",arr[i]);
	}
printf("\n");
}
