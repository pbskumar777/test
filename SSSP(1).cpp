#include<bits/stdc++.h>
using namespace std;
class parentfinder{
    public:
    int vertex;
    int parent = -9;

    parentfinder(int d){
        this->vertex = d;
    }
};

class Node{
    public:
    int data;
    Node *next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

class LinkedList{
    public:
    Node *head = NULL;
    Node *tail = NULL;

    void addEdge(int v2){
        Node *newnode = new Node(v2);
        if(head==NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = tail->next;
        }
    }
};

void sssp(vector<LinkedList> v, int vertex, vector<parentfinder> p, int dest){
    bool visited[v.size()];
    for(int i=0;i<v.size();i++){
        visited[i] = false;
    }
    queue<LinkedList> q;
    queue<int> pr;
    q.push(v[vertex]);
    pr.push(vertex);
    visited[vertex] = true;
    while(!q.empty()){
        LinkedList ob = q.front();
        int r = pr.front();
        q.pop();
        pr.pop();
        Node *temp = ob.head;
        while(temp!=NULL){
            if(visited[temp->data] == false){
                q.push(v[temp->data]);
                pr.push(temp->data);
                visited[temp->data] = true;
                if(p[temp->data].parent == -9){
                    p[temp->data].parent = r;
                }
            }
            temp = temp->next;
        }
    }

    int curr = p[dest].parent;
    cout << dest << " ";
    while(curr != -9){
        cout << curr << " ";
        curr = p[curr].parent;
    }
    
}

int main(){
    vector<LinkedList> v;
    vector<parentfinder> p;
    int V;
    cout<<"Enter vertices"<<endl;
    cin >> V;
    for(int i=0;i<V;i++){
        parentfinder ob(i);
        p.push_back(ob);
    }
    cout<<"Enter number of edges"<<endl;
    int edge;
    for(int i=0;i<V;i++){
        LinkedList obj;
        v.push_back(obj);
    }
    cin >> edge;
    cout<<"Enter edges"<<endl;
    for(int i=0;i<edge;i++){
        int v1,v2;
        cin>>v1>>v2;
        v[v1].addEdge(v2);
    }

    sssp(v,0,p,6);
}