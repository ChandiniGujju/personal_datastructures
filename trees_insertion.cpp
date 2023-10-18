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





void preorder_traversal(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}




int main(){
    node* root=NULL;
    insertion(root,10);
    insertion(root,5);
    insertion(root,15);
    insertion(root,3);
    insertion(root,7);
    preorder_traversal(root);
}
