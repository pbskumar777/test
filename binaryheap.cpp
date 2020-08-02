#include<bits/stdc++.h>
using namespace std;
void heapify2(int arr[],int size,int n,int l1,int l2){
    if(l1>size || l2>size){
        return;
    }
    int temp = arr[l1];
    arr[l1] = arr[l2];
    arr[l2] = temp;
    if(arr[l2]>arr[l2*2]){
        heapify2(arr,size,n,l2,l2*2);
    }
    if(arr[l2]>arr[(l2*2)+1]){
        heapify2(arr,size,n,l2,(l2*2)+1);
    }
}
void heapify(int arr[],int size,int n){
    int t = size;
    while((int)((t)/2)>0 && arr[t]<arr[(int)((t)/2)]){
        int temp = arr[(int)((t)/2)];
        arr[(int)((t)/2)] = arr[t];
        arr[t] = temp;
        t = (int)(t/2);
    }
}
void deletemin(int arr[],int *size,int n){
    arr[1] = arr[*size];
    (*size)--;
    int k = (*size);
    if(arr[1]>arr[2]){
        heapify2(arr,k,n,1,2);
    }
    if(arr[1]>arr[3]){
        heapify2(arr,k,n,1,3);
    }
}
void display(int arr[],int n){
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int size = 0;
    int arr[n+1] = {0};
    for(int i=1;i<=n;i++){
        if(size<n){
            int val;
            cin>>val;
            arr[size+1] = val;
            size++;
            heapify(arr,size,val);
        }
        else{
            cout<<"Overflow"<<endl;
        }
    }
    display(arr,size);
    deletemin(arr,&size,n);
    display(arr,size);
}