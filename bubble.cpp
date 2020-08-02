#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }    
}
int main(){
    int arr[10] = {12,45,1,5,34,23,87,32,20,15};
    bubblesort(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}