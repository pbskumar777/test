#include<bits/stdc++.h>
using namespace std;
void insertionsort(int arr[],int size){
    for(int i=1;i<size;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }    
}
int main(){
    int arr[10] = {12,45,1,5,34,23,87,32,20,15};
    insertionsort(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}