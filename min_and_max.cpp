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
     if(val<=root->data){
        insertion(root->left,val);
     }
     else{
        insertion(root->right,val);
     }
 }



 bool searching(node* root,int val){
     if(root==NULL){
        return false;
     }
     if(val==root->data){
        return true;
     }
     else if(val<=root->data){
        return searching(root->left,val);
     }
     else{
        return searching(root->right,val);
     }
 }






 void traversal(node* root){
     if(root==NULL){
        return;
     }
     cout<<root->data<<" ";
     traversal(root->left);
     traversal(root->right);
 }





 int findMin(node* root){
     if(root->left!=NULL){
        root=root->left;
     }
     return root->data;
 }
 int findMax(node* root){
     if(root->right!=NULL){
        root=root->right;
     }
     return root->data;
 }





 int main(){
     node* root=NULL;
     insertion(root,5);
     insertion(root,3);
     insertion(root,8);
     traversal(root);
     cout<<endl;
     cout<<findMin(root)<<endl;
     cout<<findMax(root)<<endl;
     cout<<searching(root,9)<<endl;
 }
