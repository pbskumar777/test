#include<bits/stdc++.h>
using namespace std;
void fact(int n){
    int val = n;
    goto imp;
    imp:
        if(n==1 or n==0){
            goto done;
        }
        else{
            goto cont;
        }
    done:
        cout<<val;
        return;
    cont:
        val *= (n-1);
        n= n-1;
        goto imp;
}
int main(){
  int n = 7;
  fact(n);
}