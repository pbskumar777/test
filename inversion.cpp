#include<bits/stdc++.h>
using namespace std;
void updateit(int BIT[],int maxar,int index,int val){
    while(index<=maxar){
        BIT[index]+=val;
        index += index & (-index);
    }
}
int sumit(int BIT[],int index){
    int su = 0;
    while(index>0){
        su+=BIT[index];
        index-=index & (-index);
    }
    return su;

}
int inversion(int arr[],int n){
    int res = 0;
    int maxar = 0;
    for(int i=0;i<n;i++){
        if(maxar<arr[i]){
            maxar = arr[i];
        }
    }
    int BIT[maxar+1];
    for(int i=1;i<=maxar;i++){
        BIT[i] = 0;
    }
    for(int i = n-1;i>=0;i--){
        res += sumit(BIT,arr[i]-1);
        updateit(BIT,maxar,arr[i],1);
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result = inversion(arr,n);
    cout<<result;
    return 0;
}