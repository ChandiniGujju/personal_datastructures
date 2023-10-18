//postfix to prefix

#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
string postfixToPrefix(string s){
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
            st.push(op1+op2+s[i]);
        }
    }
    return st.top();
}
int main(){

    string p=postfixToPrefix("abc/-ak/l-*");
    reverse(p.begin(),p.end());
    cout<<p<<endl;
}

