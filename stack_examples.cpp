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
