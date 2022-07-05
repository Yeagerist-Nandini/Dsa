#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;   
    Node* right;
    
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

//  left hota h 
void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}


void kLevel(Node* root,int k)
{
    if(root==NULL || k<0)
    return ;

    if(k==0)
    cout<<root->data<<" ";

    kLevel(root->left,k-1);
    kLevel(root->right,k-1);
}

int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7 

    // preorder(root); //1 2 4 5 3 6 7
    kLevel(root,0);
    return 0;
}