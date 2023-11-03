//time complexity=O(n);

#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
public:
    node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* insertion(node* &root, int val) {
    if(root == NULL) {
        return new node(val);
    }
    else if(root->data > val) {
        root->left = insertion(root->left, val);
    }
    else {
        root->right = insertion(root->right, val);
    }
    return root;
}

node* findMin(node* root){
    while(root && root->left != NULL)
        root = root->left;
    return root;
}

node* deletion(node* root,int val){
    if(root==NULL){
        return root;
    }
    else if(val < root->data){
        root->left=deletion(root->left,val);
    }
    else if(val > root->data){
        root->right=deletion(root->right,val);
    }
    else{
        if(root->left==NULL){
            node* temp= root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        node* temp=findMin(root->right);
        root->data=temp->data;
        root->right=deletion(root->right,temp->data);
    }
    return root;
}

void inorder(node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node* root = NULL;
    root = insertion(root, 6);
    root = insertion(root, 7);
    root = insertion(root, 9);
    root = insertion(root, 4);
    root = insertion(root, 2);
    inorder(root);
    root = deletion(root,7); // Corrected line
    cout << endl;
    inorder(root);
}


