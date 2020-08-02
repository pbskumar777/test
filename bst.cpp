#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
};
Node *goleft(Node *root){
    while(root->left){
        root = root->left;
    }
    return root;
}

Node* delet(Node *root,int val){
    if(root==NULL){
        return root;
    }
    else if(val<root->data){
        root->left = delet(root->left,val);
    }
    else if(val>root->data){
        root->right = delet(root->right,val);
    }
    else{
        if (root->left == NULL) 
        { 
            Node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            Node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        Node *temp = goleft(root->right);
        root->data = temp->data; 
        root->right = delet(root->right, temp->data); 
    }
    return root;
}

Node *insert(int val,Node *root){
    if(root==NULL){
        Node *temp = new Node();
        temp->data = val;
        root = temp;
        return root;
    }
    if(val < root->data){
        root->left = insert(val,root->left);
    }
    else{
        root->right = insert(val,root->right);
    }
    return root;
}

void display(Node *root){
    if(root==NULL){
        return;
    }
    else{
        display(root->left);
        cout<<root->data<<" ";
        display(root->right);
    }
}

void pushall(int arr[],int n,Node *root){
    for(int i=0;i<n;i++){
        if(root==NULL){
            Node *temp = new Node();
            temp->data = arr[i];
            root = temp;
        }
        else{
            root = insert(arr[i],root);
        }
    }

    display(root);
    cout<<endl;
    root = delet(root,34);
    display(root);
    root = delet(root,67);
    display(root);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *root = NULL;
    pushall(arr,n,root);
}