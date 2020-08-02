#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int height=0;
    Node *left;
    Node *right;
};

int height(Node *root){
    if(root==NULL){
        return -1;
    }
    int left = height(root->left);
    int right = height(root->right);
    if(left>right){
        return left+1;
    }
    return right+1;
}

Node* rightrotate(Node *root){
    Node *temp = root->left;
    Node *temp2 = temp->right;
    temp->right = root;
    root->left = temp2;
    root->height = height(root);
    temp->height = height(temp);
    return temp;
}

Node* leftrotate(Node *root){
    Node *temp = root->right;
    Node *temp2 = temp->left;
    temp->left = root;
    root->right = temp2;
    root->height = height(root);
    temp->height = height(temp);
    return temp;
}

void display(Node* root){
    if(root==NULL){
        return;
    }
    display(root->left);
    cout<<root->data<<" "<<endl;
    display(root->right);
}

Node* insert(Node *root,int val){
    if(root==NULL){
        Node *temp = new Node();
        temp->data = val;
        root = temp;
        return root;
    }
    else{
        if(val<root->data){
            root->left = insert(root->left,val);
        }
        else{
            root->right = insert(root->right,val);
        }
    }
    root->height = height(root);
    int balance = height(root->left) - height(root->right);
    if(balance>1 && val<root->left->data){      //LL
        return rightrotate(root);
    }
    else if(balance > 1 && val>root->left->data){        //LR
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }
    else if(balance < -1 && val>root->right->data){           //RR
        return leftrotate(root);
    }
    else if(balance < -1 && val < root->right->data){          //RL
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
}

Node* pushall(Node *root,int arr[],int n){
    for(int i=0;i<n;i++){
        if(root==NULL){
            Node *temp = new Node();
            temp->data = arr[i];
            root = temp;
        }
        else{
            root = insert(root,arr[i]);
        }
    }
    return root;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node *root = NULL;
    root = pushall(root,arr,n);
    display(root);
}