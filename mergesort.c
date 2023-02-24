/*
*2023/2/24
*divide and conquer
*divide O(n)
*merge compare N times total merge logN --> O(nlongn)
*/


#include<stdio.h>
#include<stdlib.h>

#define pin(k) printf("%d \n",k);
#define size(arr) (sizeof(arr))/(sizeof(arr[0]))

void mergeSort(int*,int,int);
void merge(int*,int,int,int);
void printArr(int*);

static int cnt = 0;

void mergeSort(int* arr,int l,int r){
    int mid = (l+r)/2;
    pin(mid);
    if(l < r){
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }

}
void merge(int* arr,int l,int m,int r){
    printf("cnt : %d \n",cnt++);
    int arrLeftNum = m-l+1;
    int arrRightNum = r-m;
    int arrLeft[arrLeftNum];
    int arrRight[arrRightNum];

    for(int i = 0;i<arrLeftNum;i++){
        arrLeft[i] = arr[l+i];
    }
    for(int i = 0;i<arrRightNum;i++){
        arrRight[i] = arr[m+i+1];
    }
    int q,w,e;
    q = w = 0;
    e = l;
    while(q < arrLeftNum && w < arrRightNum ){
        if(arrLeft[q] < arrRight[w]){
            arr[e] = arrLeft[q];
            q++;
        }else{
            arr[e] = arrRight[w];
            w++;
        }
        e++;
    }
    while(q < arrLeftNum){
        arr[e] = arrLeft[q];
        e++;
        q++;
    }
    while(w < arrRightNum){
        arr[e] = arrRight[w];
        e++;
        w++;
    }
}
void printArr(int* arr){
    for(int i = 0;i<size(arr);i++){
        printf("%d ",arr[i]);
    }
}
int main(void){
    int k[] = {6,5,4,3,2,1};
    mergeSort(k,0,size(k)-1);
    printArr(k);
    return 0;
}