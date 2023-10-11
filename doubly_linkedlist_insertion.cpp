#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* prev;
    node* next;
    node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};









void insert_at_head(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    if(head!=NULL)
        head->prev=n;
    head=n;
}







void insert_at_tail(node* &head,int val){//time complexity O(n)
    if(head==NULL){
        insert_at_head(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}







void insert_at_tail1(node* &head,node* &tail,int val){//time complexity O(1)
    node* n=new node(val);
    if(tail==NULL){
        head=n;
        tail=n;
        return;
    }
    tail->next=n;
    n->prev=tail;
    tail=n;
    return;
}











void insert_at_position(node* head,int val,int p){
    node* n=new node(val);
    n->data=val;
    if(head==NULL){
        insert_at_head(head,val);
        return;
    }
    node* temp=head;
    for(int i=0;i<p-1;i++){
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
    n->prev=temp;
    n->next->prev=n;

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
    node* tail=NULL;
    insert_at_tail1(head,tail,10);
    insert_at_tail1(head,tail,12);
    print(head);
    cout<<endl;
    insert_at_head(head,8);
    insert_at_head(head,6);
    print(head);
    insert_at_position(head,4,2);
    insert_at_position(head,9,4);
    print(head);
    cout<<endl;
}




