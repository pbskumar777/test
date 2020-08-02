// factorial program
#include<bits/stdc++.h>
using namespace std;
void recur(string s,int start,int end){
    if(start==end){
        cout<<s<<endl;
    }
    else{
        for(int i = start;i<=end;i++){
            swap(s[start],s[i]);
            recur(s,start+1,end);
            swap(s[i],s[start]);
        }
    }
}
int main(){
    string s = "ABC";
    recur(s,0,2);
}