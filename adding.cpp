#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
Node* addNodes(Node *head,Node *tail){
        int size;
        cin>>size;
        for(int i=0;i<size;i++){
            int val;
            cin>>val;
            Node *temp = new Node();
            temp->data = val;
            if(head==NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
        }
        return head;
}
void print(Node *head){
        Node *temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
}
Node* adding(Node *head1,Node *head2){
    Node *temp1=head1,*temp2=head2;
    string s1,s2;
    while(temp1!=NULL){
        s1+=to_string(temp1->data);
        temp1 = temp1->next;
    }
    while(temp2!=NULL){
        s2+=to_string(temp2->data);
        temp2 = temp2->next;
    }
    int su = stoi(s1)+stoi(s2);
    Node *head3 = NULL;
    int rem;
    while(su!=0){
        rem = su%10;
        su = su/10;
        Node *newt = new Node();
        newt->data = rem;
        if(head3==NULL){
            head3 = newt;
        }
        else{
            newt->next = head3;
            head3 = newt;
        }
    }
    return head3;
}
int main(){
    Node *head1=NULL,*head2 = NULL,*head3=NULL;
    Node *tail1=NULL,*tail2=NULL;
    head1 = addNodes(head1,tail1);
    head2 = addNodes(head2,tail2);
    head3 = adding(head1,head2);
    print(head3);
}