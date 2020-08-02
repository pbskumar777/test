#include<bits/stdc++.h>
using namespace std;
tuple<int,int,string> usethese(){
    int l = 55;
    int j = 25;
    string s = "shiva";
    return make_tuple(l,j,s);
}
pair<string,string> useit(){
    return make_pair("shiva","Kumar");
}
int main(){
  int k,k1;
  string s1;
  tie(k,k1,s1)= usethese();
  pair<string,string> d = useit();
  cout<<d.first<<" "<<d.second;
}