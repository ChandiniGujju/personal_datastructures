
//array implementation of stacks

#include<iostream>
using namespace std;
#define n 100
class stack{
    int top;
    int* arr;
public:
    stack(){
        top=-1;
        arr=new int[n];
    }
    void push(int a){
        if(top==n-1){
            cout<<"stack overflow"<<endl;
            return;
        }
        top++;
        arr[top]=a;
    }
    void pop(){
        if(top==-1){
            cout<<"stack underflow"<<endl;
            return;
        }
        top--;
    }
    int peek(){
        if(top==-1){
            cout<<"stack underflow"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==n-1;
    }
};
int main(){
    stack st;
    st.push(9);
    st.push(8);
    st.push(7);
    st.push(6);
    st.pop();
    st.pop();
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.isEmpty()<<endl;
    cout<<st.isFull()<<endl;
}









//copy stack to another in same order

#include<iostream>
#include<stack>
using namespace std;
void copystack(stack<int> &source,stack<int> &destination){
    stack<int> temp;
    while(!source.empty()){
        temp.push(source.top());
        source.pop();
    }
    while(!temp.empty()){
        int e=temp.top();
        source.push(e);
        destination.push(e);
        temp.pop();
    }
}
int main(){
    stack<int> source,destination;
    source.push(1);
    source.push(2);
    source.push(3);
    source.push(4);
    copystack(source,destination);
    while(!destination.empty()){
        cout<<destination.top()<<" ";
        destination.pop();
    }
}






#include<iostream>
#include<stack>
using namespace std;
void copystack(stack<int>& source,stack<int>& destination){
    if(source.empty()){
        return;
    }
    int element=source.top();
    source.pop();
    copystack(source,destination);
    destination.push(element);
    source.push(element);
    //copystack(source,destination);
}
int main(){
    stack<int> source,destination;
    source.push(1);
    source.push(2);
    source.push(3);
    source.push(4);
    copystack(source,destination);
    while(!destination.empty()){
        cout<<destination.top()<<" ";
        destination.pop();
    }
}






//reversing stack

#include<iostream>
#include<stack>
using namespace std;
void reversestack(stack<int>& original){
    stack<int> temp;
    while(!original.empty()){
        temp.push(original.top());
        original.pop();
    }
    original=temp;
}
int main(){
    stack<int> original;
    original.push(1);
    original.push(2);
    original.push(3);
    original.push(4);
    reversestack(original);
    while(!original.empty()){
        cout<<original.top()<<" ";
        original.pop();
    }

}







//insertion at end of stack

#include<iostream>
#include<stack>
using namespace std;
void addAtBottom(stack<int>& original,int val){
    stack<int> temp;
    if(original.empty()){
        original.push(val);
        return;
    }
    while(!original.empty()){
        temp.push(original.top());
        original.pop();
    }
    original.push(val);
    while(!temp.empty()){
        original.push(temp.top());
        temp.pop();
    }
}
void print(stack<int> original){
    while(!original.empty()){
        cout<<original.top()<<" ";
        original.pop();
    }
}
int main(){
    stack<int> original;
    int val;
    cin>>val;
    original.push(1);
    original.push(2);
    original.push(3);
    original.push(4);
    addAtBottom(original,val);
    print(original);

}






//insertion at kth place

#include<iostream>
#include<stack>
using namespace std;
void addAtPos(stack<int>& original,int val,int pos){
    stack<int> temp;
    if(original.empty()){
        original.push(val);
        return;
    }
    for(int i=1;i<pos;i++){
        temp.push(original.top());
        original.pop();
    }
    original.push(val);
    while(!temp.empty()){
        original.push(temp.top());
        temp.pop();
    }
}
void print(stack<int> original){
    while(!original.empty()){
        cout<<original.top()<<" ";
        original.pop();
    }
}
int main(){
    stack<int> original;
    int val,pos;
    cin>>val>>pos;
    original.push(1);
    original.push(2);
    original.push(3);
    original.push(4);
    addAtPos(original,val,pos);
    print(original);

}

