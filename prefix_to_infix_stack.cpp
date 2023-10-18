//prefix to infix

#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
string prefixToInfix(string s){
    reverse(s.begin(),s.end());
    stack<string> st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || isdigit(s[i])){
            string op(1,s[i]);
            st.push(op);
        }
        else{
            string op1=st.top();
            st.pop();
            string op2=st.top();
            st.pop();
            st.push("("+op1+s[i]+op2+")");
        }
    }
    return st.top();
}
int main(){

    string p=prefixToInfix("*-a/bc-/akl");
    //reverse(p.begin(),p.end());
    cout<<p<<endl;
}
