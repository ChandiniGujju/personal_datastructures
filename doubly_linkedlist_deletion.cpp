#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};







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









void delete_at_start(node* &head,node* &tail){
    if(head==NULL){
        return;
    }
    node* temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    else{
        tail=NULL;
    }
    delete temp;
    return;
}






void delete_at_tail(node* &head,node* &tail){

    if(head==NULL){
        return;
    }
    node* temp=tail;
    tail=tail->prev;
    if(tail!=NULL){
        tail->next=NULL;
    }
    else{
        head=NULL;
    }
    delete temp;
    return;
}







void delete_at_pos(node* head,node* tail,int pos){
    node* temp=head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
    return;
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
    insert_at_tail1(head,tail,2);
    insert_at_tail1(head,tail,4);
    insert_at_tail1(head,tail,6);
    insert_at_tail1(head,tail,8);
    insert_at_tail1(head,tail,10);
    insert_at_tail1(head,tail,12);
    print(head);
    delete_at_start(head,tail);
    print(head);
    delete_at_tail(head,tail);
    print(head);
    delete_at_pos(head,tail,2);
    print(head);
}
