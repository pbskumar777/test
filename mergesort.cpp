#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int l,int mid,int r){
    int n1 = mid-l+1;
    int n2 = r-mid;
    int Left[n1],Right[n2];
    for(int i=0;i<n1;i++){
        Left[i] = arr[l+i];
    }
    for(int j=0;j<n2;j++){
        Right[j] = arr[mid+1+j];
    }
    int k = l;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(Left[i]<=Right[j]){
            arr[k] = Left[i];
            i++;
        }
        else{
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=Left[i];
        i++;
        k++;
    }
    while(i<n2){
        arr[k] = Right[j];
        j++;
        k++;
    }

}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int mid = (l+r)/2;
        mergesort(arr,0,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int arr[10] = {12,45,1,5,34,23,87,32,20,15};
    mergesort(arr,0,10);
    for(int j=0;j<10;j++){
        cout<<arr[j]<<" ";
    }
}