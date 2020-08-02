#include<bits/stdc++.h>
using namespace std;
char *sak;
int prec(char ch){
    if(ch=='^'){
        return 3;
    }
    else if(ch=='*' || ch == '/'){
        return 2;
    }
    else if(ch=='+' || ch =='-'){
        return 1;
    }
    else{
        return -1;
    }
}
char* convert(char *arr,int n){
    string ns="";
    stack<char> st;
    st.push('N');
    for(int i=0;i<n;i++){
        if(int(arr[i])>=48 && int(arr[i])<=57){
            ns+=arr[i];
        }
        else if(arr[i]=='('){
            st.push(arr[i]);
        }
        else if(arr[i]==')'){
            while(st.top()!='N' && st.top()!='('){
                char c = st.top();
                ns+=c;
                st.pop();
            }
            if(st.top()=='('){
                st.pop();
            }
        }
        else{
            while(st.top()!='N' && prec(arr[i])<=prec(st.top())){
                char c = st.top();
                ns+=c;
            }
            st.push(arr[i]);
        }
    }
    while(st.top()!='N'){
        char c = st.top();
        ns+=c;
        st.pop();
    }
    int i=0;
    for(;i<ns.length();i++){
        arr[i] = ns[i];
    }
    if(n>i){
        arr[i]='\0';
    }
    return arr;

}
int main(){
    char arr[5] = {'1','+','(','8',')'};
    char *p = convert(arr,5);
    int i=0;
    while(i<strlen(p)){
        cout<<p[i];
        i++;
    }
    return 0;
}