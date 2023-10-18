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
