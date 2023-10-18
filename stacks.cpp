
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
        source.push(temp.top());
        destination.push(temp.top());
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







//Balanced bracket sequence

#include<iostream>
#include<stack>
using namespace std;
void isValid(string str){
    stack<char> Stack;
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(ch=='(' || ch=='[' || ch=='{'){
            Stack.push(ch);
        }
        else{
            if(ch==')' && !Stack.empty() && Stack.top()=='('){
                Stack.pop();
            }
            else if(ch==']' && !Stack.empty() && Stack.top()=='['){
                Stack.pop();
            }
            else if(ch=='}' && !Stack.empty() && Stack.top()=='{'){
                Stack.pop();
            }
            else{
                cout<<"pattern is invalid"<<endl;
                return;
            }
        }
    }
    if(Stack.empty()){
        cout<<"Pattern is valid"<<endl;
    }
    else{
        cout<<"Pattern is invalid"<<endl;
    }

}
int main(){
    string str;
    getline(cin,str);
    isValid(str);
}






//next greater element

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> nge(vector<int> &arr){
    int n=arr.size();
    vector<int> output(n,-1);
    stack<int> st;
    st.push(0);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]>arr[st.top()]){
            output[st.top()]=arr[i];
            st.pop();
        }
        st.push(i);
    }
    return output;
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    while(n--){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> res=nge(v);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}




//reverse a sentence

#include<iostream>
#include<stack>
using namespace std;
void reverseSentence(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
int main(){
    string s="hello how are you";
    reverseSentence(s);
}




//reversing the string

#include<iostream>
#include<stack>
using namespace std;
void reverseString(string& s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }
    for(int i=0;i<s.length();i++){
        s[i]=st.top();
        st.pop();
    }
    cout<<s<<endl;

}
int main(){
    string s="CHANDINI";
    reverseString(s);
}





//prefix evaluation

#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int prefix(string s){
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');//If s[i] is '3', the ASCII value of '3' is 51, and the ASCII value of '0' is 48. So, s[i]-'0' evaluates to 51 - 48, which is 3.
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            switch(s[i]){
            case'+':
                st.push(op1+op2);
                break;
            case'-':
                st.push(op1-op2);
                break;
            case'*':
                st.push(op1*op2);
                break;
            case'/':
                st.push(op1/op2);
                break;
            case'%':
                st.push(op1%op2);
                break;
            case'^':
                st.push(pow(op1,op2));
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}
int main(){
    cout<<prefix("-+7*45+20")<<endl;
}






//postfix evaluation

#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int postfix(string s){
    stack<int> st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0'&&s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            switch(s[i]){
            case'+':
                st.push(op1+op2);
                break;
            case'-':
                st.push(op1-op2);
                break;
            case'*':
                st.push(op1*op2);
                break;
            case'/':
                st.push(op1/op2);
                break;
            case'%':
                st.push(op1%op2);
                break;
            case'^':
                st.push(pow(op1,op2));
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}
int main(){
    cout<<postfix("23*5+")<<endl;
}




//infix evaluation

#include<iostream>
#include<stack>
#include<math.h>
#include<string>
using namespace std;

int getPrecedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: break;
    }
}

int evaluateInfix(string s) {
    stack<int> operands;
    stack<char> operators;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == ' ') {
            continue;
        } else if (isdigit(c)) {
            operands.push(c - '0');
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int b = operands.top(); operands.pop();
                int a = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                operands.push(applyOperation(a, b, op));
            }
            operators.pop();
        } else {
            while (!operators.empty() && getPrecedence(c) <= getPrecedence(operators.top())) {
                int b = operands.top(); operands.pop();
                int a = operands.top(); operands.pop();
                char op = operators.top(); operators.pop();
                operands.push(applyOperation(a, b, op));
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        int b = operands.top(); operands.pop();
        int a = operands.top(); operands.pop();
        char op = operators.top(); operators.pop();
        operands.push(applyOperation(a, b, op));
    }

    return operands.top();
}

int main() {
    string s;
    cout << "Enter an infix expression: ";
    getline(cin, s);
    cout << evaluateInfix(s) << endl;
    return 0;
}






//infix to postfix

#include<iostream>
#include<stack>
#include<string>
#include<math.h>
using namespace std;
int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return -1;
    }
}
string infixToPostfix(string s){
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a'&&s[i]<='z' || s[i]>='A'&&s[i]<='Z'|| isdigit(s[i])){
            res+=s[i];
        }
        else if(s[i]=='('){
               st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                 res+=st.top();
                 st.pop();
            }
            if(!st.empty())
                st.pop();
        }
        else{
            while(!st.empty()&&precedence(st.top())>precedence(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}
int main(){
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;
}
//3+4×2/(1−5)
//(a-b/c)*(a/k-l)




//infix to prefix--->same as postfix but we need to string first given and also result string and change'(' to ')' vice-versa

#include<iostream>
#include<stack>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
int precedence(char c){
    if(c=='^')
        return 3;
    else if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return -1;
}
string infixToPrefix(string s){
    reverse(s.begin(),s.end());
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a'&&s[i]<='z' || s[i]>='A'&&s[i]<='Z'|| isdigit(s[i])){
            res+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            while(!st.empty()&&st.top()!=')'){
                  res+=st.top();
                  st.pop();
            }
            if(!st.empty())
                st.pop();
        }
        else{
            while(!st.empty()&&precedence(st.top())>=precedence(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }

    }
    while(!st.empty()){
            res+=st.top();
            st.pop();
    }
    reverse(res.begin(),res.end());
    return res;
}
int main(){
    cout<<infixToPrefix("(a-b/c)*(a/k-l)")<<endl;
}


