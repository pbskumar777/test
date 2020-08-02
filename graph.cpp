#include<bits/stdc++.h>
using namespace std;
int main(){
    int V;
    cin>>V;
    vector<int> edge[V];
    int edges;
    cin>>edges;
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        edge[u-1].push_back(v);
    }
    cout<<"Edges here"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<edge[i].size();j++){
            cout<<i+1<<" "<<edge[i][j];
        }
        cout<<endl;
    }
}