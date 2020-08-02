#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int mun(int arr[],int l,int r){
    int min = arr[l];
    int ind = l;
    for(int i=l+1;i<r;i++){
        if(arr[i]<min){
            min = arr[i];
            ind = i;
        }
    }
    return ind;
}
void selectionsort(int arr[],int size){
    for(int i=0;i<size;i++){
        int ind = mun(arr,i,size);
        swap(&arr[i],&arr[ind]);
    }
}
int main(){
    int arr[10] = {12,45,1,5,34,23,87,32,20,15};
    selectionsort(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}