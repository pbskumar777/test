#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};
Node *seggregate(Node *head){
    Node *lasteven = NULL;
    Node *newhead = NULL;
    Node *temp = head;
    while(temp!=NULL){
        if((temp->data)%2==0){
            lasteven = temp;
        }
        temp = temp->next;
    }
    if(lasteven==NULL){
        return head;
    }
    Node *temp2 = head;
    while(temp2!=NULL){
        if((temp2->data)%2==0){
            newhead = temp2;
            break;
        }
    }
    Node *temp3 = head;
    while(temp3!=NULL){
        if(temp3->data%2!=0){
            Node *interm = lasteven->next;
            lasteven->next = temp3;
            lasteven = lasteven->next;
            lasteven->next = interm;
        }
    }
    return newhead;
}
Node *push(int s1){
    Node *tail = NULL;
    Node *head = NULL;
    for(int j=0;j<s1;j++){
        int d;
        cin>>d;
        Node *temp = new Node();
        temp->data = d;
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
int main()
 {
    int test;
    cin>>test;
    for(int i=0;i<test;i++){
        int s1;
    	cin>>s1;
    	Node *head = push(s1);
    	head = seggregate(head);
    	while(head!=NULL){
    	    cout<<head->data<<" ";
    	    head = head->next;
    	}
    	cout<<"/n";
    }
	return 0;
}