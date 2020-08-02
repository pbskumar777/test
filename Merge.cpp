#include<bits/stdc++.h>
using namespace std;
void qsort(int arr[],int l,int r){
    int j=0;
    int i = j-1;
    int pivot = r;
    while(j<=pivot){
        if(arr[j]<=arr[pivot]){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    return i;
}
void quicksort(int arr[],int l,int r){
    if(l<r){
        int pivot = qsort(arr,l,r);
        quicksort(arr,l,pivot-1);
        quicksort(arr,pivot+1,r);
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n);
}