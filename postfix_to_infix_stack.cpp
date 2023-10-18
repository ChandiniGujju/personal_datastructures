//postfix to infix

#include<iostream>
#include<stack>
#include<string>
using namespace std;
string postfixToInfix(string s){
    stack<string> st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || isdigit(s[i])){
            //string op(1,s[i]);
            string op;
            op+=s[i];
            st.push(op);
        }
        else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            st.push("("+op2+s[i]+op1+")");
        }
    }
    return st.top();
}
int main(){

    cout<<postfixToInfix("abc/-ak/l-*")<<endl;
}
