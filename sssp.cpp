#include<bits/stdc++.h>
using namespace std;

class buildheapnode {
    public:
    int vertex;
    int distance;
};

class Node{
    public:
    int vertex;
    int weight;
    Node *next;

    Node(int d, int w){
        this->vertex = d;
        this->weight = w;
        this->next = NULL;
    }
};

class LinkedList{
    public:
    Node *head = NULL;
    Node *tail = NULL;

    void addEdge(int v2, int weight){
        Node *newnode = new Node(v2, weight);
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

void reheapify(buildheapnode arr[],int size,int n,int l1,int l2, int storepos[]){
    if(l1>size || l2>size){
        return;
    }
    storepos[arr[l1].vertex] = l2;
    storepos[arr[l2].vertex] = l1;
    buildheapnode temp = arr[l1];
    arr[l1] = arr[l2];
    arr[l2] = temp;
    if(arr[l2].distance > arr[l2*2].distance){
        reheapify(arr,size,n,l2,l2*2,storepos);
    }
    if(arr[l2].distance > arr[(l2*2)+1].distance){
        reheapify(arr,size,l2,n,(l2*2)+1,storepos);
    }
}

void heapify(buildheapnode heap[], int size, int storepos[]){
    int t = size;
    while((int)((t)/2)>0 && heap[t].distance <= heap[(int)((t)/2)].distance){
        storepos[heap[t].vertex] = (int)((t)/2);
        storepos[heap[(int)((t)/2)].vertex] = t; 
        buildheapnode temp = heap[(int)((t)/2)];
        heap[(int)((t)/2)] = heap[t];
        heap[t] = temp;
        t = (int)(t/2);
    }
}

void sssp(vector<LinkedList> v, int source){
    int size = 0;
    int storepos[v.size()];
    buildheapnode heap[v.size()+1];
    int dist[v.size()];
    for(int i=1;i<v.size()+1;i++){
        if(i-1 == source){
            buildheapnode ob;
            ob.vertex = source;
            ob.distance = 0;
            storepos[i-1] = source+1;
            heap[i] = ob;
            size++;
            heapify(heap,size,storepos);
            dist[i-1] = 0;
        }
        else{
            buildheapnode obj;
            obj.vertex = i-1;
            obj.distance = INT_MAX;
            storepos[i-1] = i-1;
            heap[i] = obj;
            size++;
            heapify(heap,size,storepos);
            dist[i-1] = INT_MAX;
        }
    }

    while(size>0){
        buildheapnode o = heap[1];
        heap[1] = heap[size];
        storepos[heap[size].vertex] = 1;
        size--;
        int k = size;
        if(heap[1].distance > heap[2].distance){
            reheapify(heap,k,v.size(),1,2, storepos);
        }
        if(heap[1].distance > heap[3].distance){
            reheapify(heap,k,v.size(),1,3, storepos);
        }
        LinkedList o2 = v[o.vertex];
        Node *temp = o2.head;
        while(temp!=NULL){
            if(o.distance + temp->weight < dist[temp->vertex]){
                dist[temp->vertex] = o.distance + temp->weight;
                heap[storepos[temp->vertex]].distance = o.distance + temp->weight;
                heapify(heap,size,storepos);
                cout<<endl;
            }
            temp = temp->next;
        }
    }
    for(int i=0;i<v.size();i++){
        cout<< dist[i] << endl;
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
        int v1,v2,weight;
        cin>>v1>>v2>>weight;
        v[v1].addEdge(v2,weight);
    }
    sssp(v,8);
}