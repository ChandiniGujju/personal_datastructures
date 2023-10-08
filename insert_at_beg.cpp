#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insert_at_begin(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node* head=NULL;
    insert_at_begin(head,3);
    insert_at_begin(head,4);
    insert_at_begin(head,5);
    insert_at_begin(head,6);
    print(head);
}
