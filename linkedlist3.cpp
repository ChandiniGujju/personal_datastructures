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
    print(head);
}





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
void add_at_tail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
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
    add_at_tail(head,8);
    add_at_tail(head,9);
    add_at_tail(head,7);
    print(head);
}





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
void add_at_pos(node* head,int val,int pos){
    node* n=new node(val);
    if(pos==1){
        n->next=head;
        head=n;
        return;
    }
    node* temp=head;
    for(int i=1;i<pos-1&&temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        cout<<" invalid position"<<endl;
        delete n;
        return;
    }
    n->next=temp->next;
    temp->next=n;
}
void add_at_head(node* &head,int val){
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
    add_at_head(head,8);
    add_at_head(head,9);
    add_at_head(head,7);
    print(head);
    add_at_pos(head,6,2);
    print(head);
}



























