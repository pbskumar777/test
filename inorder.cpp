#include<bits/stdc++.h>
using namespace std;
class Node{
  public:
  int data;
  Node *left;
  Node *right;
};
void inorder(Node *head){
  if(head==NULL){
    return;
  }
  else{
    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
  }
}
Node *createTree(int arr[],int l,int r){
  if(l>=r){
    Node *nnode = new Node();
    nnode->data = arr[l];
    nnode->left = NULL;
    nnode->right = NULL;
    return nnode;

  }
  int ind = (int)(l+r)/2;
  Node *temp = new Node();
  temp->data = arr[ind];
  temp->left = createTree(arr,l,ind-1);
  temp->right = createTree(arr,ind+1,r);
  return temp;
}
int main(){
  Node *head = NULL;
  int arr[15] = {8,4,9,2,10,5,11,1,12,6,13,3,14,7,15};
  head = createTree(arr,0,14);
  inorder(head);
  
}