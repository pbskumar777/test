#include<bits/stdc++.h>
using namespace std;
void bfs(int vertices, int adj[5][5], int vertex){
    bool visited[vertices];
    for(int i=0;i<vertices;i++){
        visited[i] = false;
    }
    queue<int> q;
    q.push(vertex);
    visited[vertex] = true;
    cout<< vertex <<" ";
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i=0;i<vertices;i++){
            if(visited[i]==false  && adj[v][i] == 1){
                cout<< i <<" ";
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main(){
    int vertices;
    cout<<"Enter vertices"<<endl;
    cin>>vertices;
    int adj[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            adj[i][j] = 0;
        }
    }
    cout<<"Enter number of edges";
    int edge;
    cin>>edge;
    cout<<"Enter edges";
    for(int i=0;i<edge;i++){
        int v1,v2;
        cin>>v1>>v2;
        adj[v1][v2] = 1;
        adj[v2][v1] = 1;
    }
    bfs(vertices,adj,0);
}