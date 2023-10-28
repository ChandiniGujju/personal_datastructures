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
    int height(node* root){
        if(root==NULL){
            return 0;
        }
        int leftheight=height(root->left);
        int rightheight=height(root->right);
        int ans=max(leftheight,rightheight)+1;

        return ans;
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




void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}




int main(){
    node* root=NULL;
    insertion(root,10);
    insertion(root,5);
    insertion(root,15);
    insertion(root,3);
    insertion(root,7);
    inorder(root);
    cout<<endl;
    int g = root->height(root);
    cout<<g<<endl;
}
