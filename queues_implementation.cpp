
//queues using array implementation
/*
#include<iostream>
using namespace std;
#define n 20
class queue1{
    int* arr;
    int front;
    int back;
public:
    queue1(){
        arr=new int[n];
        front=-1;
        back=-1;
    }
    void enqueue(int x){
        if(front==-1){
            front++;
        }
        if(back==n-1){
            cout<<"queue overflow";
            return;
        }
        back++;
        arr[back]=x;
    }
    void dequeue(){
        if(front==-1||front>back){
            cout<<"no element in queue"<<endl;
            return;
        }
        front++;
    }
    int peek(){
        if(front==-1||front>back){
            cout<<"no element in queue"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool isEmpty(){
         if(front==-1||front>back){
            return true;
        }
        return false;
    }
};
int main(){
    queue1 q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<q.peek()<<endl;
    q.dequeue();
    cout<<q.isEmpty()<<endl;
}
*/


//queues using linked list implementation

#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
public:
    node(int val){
        data=val;
        next=NULL;
    }
};
class queue1{
    node* front;
    node* back;
public:
    queue1(){
        front=NULL;
        back=NULL;
    }
    void push(int val){
        node* n=new node(val);
        if(front==NULL){
            back=n;
            front=n;
            return;
        }
        back->next=n;
        back=n;
    }
    void pop(){
        if(front==NULL){
            return;
        }
        node* todelete=front;
        front=front->next;
        delete(todelete);
    }
    int peek(){
        if(front==NULL){
            return -1;
        }
        return front->data;
    }
    bool empty(){
        if(front==NULL){
            return true;
        }
        return false;
    }
    void display(){
        node* temp=front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    queue1 q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.display();
    q1.pop();
    q1.display();
    cout<<q1.peek()<<endl;
    cout<<q1.empty()<<endl;
}























