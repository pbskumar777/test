#include<bits/stdc++.h>
using namespace std;
int mux(int arr[],int size){
    int max = arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
void counting(int arr[],int size){
    int max = mux(arr,size);
    int range[max+1] = {0};
    int finalise[size] = {0};
    for(int i=0;i<size;i++){
        range[arr[i]] += 1;
    }
    for(int j=1;j<max+1;j++){
        range[j] += range[j-1];
    }

    for(int k = 0;k<size;k++){
        int ran = range[arr[k]];
        finalise[ran-1] = arr[k];  
    }

    for(int l=0;l<size;l++){
        cout<<finalise[l]<<" ";
    }
}
int main(){
    int arr[10] = {6,34,98,23,56,1,32,13,67,50};
    counting(arr,10);
}