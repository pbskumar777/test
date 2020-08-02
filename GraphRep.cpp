#include<bits/stdc++.h>
using namespace std;
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

void bfs(vector<LinkedList> v, int vertex){
        bool visited[v.size()];
        for(int i=0;i<v.size();i++){
            visited[i] = false;
        }
        queue<LinkedList> q;
        q.push(v[vertex]);
        cout<< vertex << " ";
        visited[vertex] = true;
        while(!q.empty()){
            LinkedList b = q.front();
            q.pop();
            Node *temp = b.head;
            while(temp!=NULL){
                if(visited[temp->data]==false){
                    cout<< temp->data <<" ";
                    visited[temp->data] = true;
                    q.push(v[temp->data]);
                }
                temp = temp->next;
            }
        }
}

void dfs(vector<LinkedList> v, int vertex, bool visited[],int size){
    visited[vertex] = true;
    cout<< vertex << " ";
    LinkedList ob = v[vertex];
    Node *temp = ob.head;
    while(temp != NULL){
        if(visited[temp->data]==false){
            dfs(v,temp->data,visited, size);
        }
        temp = temp->next;
    }    
}

void topologicalsort(int vertex, stack<int> s, vector<LinkedList> v, bool visited[],int sizev){
    LinkedList ob = v[vertex];
    Node *temp = ob.head;
    if(temp==NULL){
        return;
    }
    while(temp!=NULL){
        if(visited[temp->data] == false){
            topologicalsort(temp->data,s,v,visited,sizev);
            s.push(temp->data);
            cout<<temp->data<<" ";
            visited[temp->data] = true;
        }
        temp = temp->next;
    }
    return;
}

void tsort(vector<LinkedList> v, stack<int> s){
    bool visited[v.size()];
    for(int i=0;i<v.size();i++){
        visited[i] = false;
    }
    for(int i=0;i<v.size();i++){
        if(visited[i]==false){
            topologicalsort(i,s,v,visited,v.size());
            if(visited[i] == false){
                s.push(i);
                cout<< i<<" ";
                visited[i] = true;
            }
        }
    }
}

int main(){
    vector<LinkedList> v;
    int V;
    cout<<"Enter vertices"<<endl;
    cin >> V;
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
    stack<int> s;
    tsort(v, s);
}