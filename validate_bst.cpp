#include<iostream>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
public:
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};



bool isBST(node* root,int minimum,int maximum){
    if(root==NULL){
        return true;
    }
    if(root->data > minimum && root->data < maximum){
        bool left=isBST(root->left,minimum,root->data);
        bool right=isBST(root->right,root->data,maximum);
        return left && right;
    }
    else{
        return false;
    }
}



bool validateBST(node* root){
    return isBST(root,INT_MIN,INT_MAX);
}



void insertion(node* &root,int val){
    node* n=new node(val);
    if(root==NULL){
        root=n;
        return;
    }
    else if(val<=root->data){
        insertion(root->left,val);
    }
    else{
        insertion(root->right,val);
    }
}





int main(){
    node* root=NULL;
    insertion(root,10);
    insertion(root,5);
    insertion(root,15);
    insertion(root,3);
    insertion(root,7);
    cout<<validateBST(root);
}
