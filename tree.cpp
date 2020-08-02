#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
};
Node *insertion(vector<int>vec,Node *root,int i,int len){
    if(i<len){
        Node *temp = new Node();
        temp->data = vec[i];
        root = temp;
        root->left = insertion(vec,root->left,2*i,len);
        root->right = insertion(vec,root->right,2*i+1,len);
    }
    return root;
}
void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
int main(){
    vector<int> vec;
    int size;
    cin>>size;
    vec.push_back(-999);
    for(int i=0;i<size;i++){
        int elem;
        cin>>elem;
        vec.push_back(elem);
    }
    Node *root = NULL;
    int len = vec.size();
    root = insertion(vec,root,1,len);
    postorder(root);

}