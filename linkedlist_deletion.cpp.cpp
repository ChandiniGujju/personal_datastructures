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




void add_at_head(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}




//case1---->deletion at head
void delete_at_head(node* &head){
    if(head==NULL){
        cout<<"linkedlist is already empty"<<endl;
    }
    node* temp=head;
    head=head->next;
    delete temp;
    temp=NULL;
}





//case2----->deleting a given value
void delete_the_val(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete_at_head(head);
        return;
    }
    node* temp=head;
    if(temp->next->data!=val){
        temp=temp->next;
    }
    node* n=new node(val);
    temp->next=temp->next->next;
    delete n;
}





//case3------>deletion at a given position
void delete_at_pos(node* &head,int pos){
    int val;
    node* temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    node* n= new node(val);
    temp->next=temp->next->next;
    delete n;
}



//case4----->deletion at tail
void delete_at_tail(node* &head){
    int val;
    node* temp=head;
    node* temp2=new node(val);
    for(int i=1;temp->next!=NULL;i++){
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=NULL;
    delete temp;
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
    add_at_head(head,8);
    add_at_head(head,9);
    add_at_head(head,7);
    add_at_head(head,1);
    add_at_head(head,2);
    add_at_head(head,3);
    print(head);
    cout<<endl;
    delete_at_head(head);
    print(head);
    cout<<endl;
    delete_the_val(head,9);
    print(head);
    cout<<endl;
    delete_at_pos(head,2);
    print(head);
    cout<<endl;
    delete_at_tail(head);
    print(head);
    cout<<endl;
}

























