#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "   Hello     This is   Shiva         Kumar";
    string k = "";
    int sp=0;
    string arr[100];
    int avail = 0;
    for(int i=0;i<s.length();i++){
    	if(s[i]==' '){
    		sp+=1;
    		if(i>0 && s[i-1]!=' '){
	    		arr[avail] = k;
	    		k = "";
	    		avail++;
    		}
    	}
    	else{
    		if(i>0 && s[i-1]==' '){
    			arr[avail] = to_string(sp);
    			sp=0;
    			avail++;
    		}
    		k+=s[i];
    	}
    }
    arr[avail] = k;
    // cout<<avail<<" ";
    // cout<<arr[avail];
    string fin= "";
    for(int i = avail;i>=0;i--){
    	fin+=arr[i]+" ";
    }
    cout<<fin;
}
