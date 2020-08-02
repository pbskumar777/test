#include<bits/stdc++.h>
using namespace std;
void swap(int *i,int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}
int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low;
    int j = high+1;
    do{
        do{
            i++;
        }while(arr[i]<pivot && i<=high);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }while(i<j);
    swap(&arr[low],&arr[j]);
    return j;

}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pos = partition(arr,low,high);
        quicksort(arr,low,pos-1);
        quicksort(arr,pos+1,high);
    }
    return;
}
int main(){
    int arr[8] = {90,2,54,23,76,38,5,43};
    quicksort(arr,0,7);
    for(int i=0;i<=7;i++){
        cout<<arr[i]<<" ";
    }
}
