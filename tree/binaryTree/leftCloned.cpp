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

Node* leftClone(Node* root)
{
    if(root==NULL)
    return NULL;

    Node* l=leftClone(root->left);
    Node* r=leftClone(root->right);

    Node* t=new Node(root->data);
    root->left=t;
    root->left->left=l;
    root->right=r;

    return root;
}

Node* backToOriginal(Node* root)
{
    if(root==NULL)
    return NULL;

    Node* l=backToOriginal(root->left->left);
    Node* r=backToOriginal(root->right);

    root->left=l;
    root->right=r;

    return root;
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
    root->right->left->right=new Node(8);
    root->right->left->left=new Node(12);
    root->right->right->right=new Node(13);
    root->right->right->left=new Node(14);
    root->left->left->left=new Node(10);
    root->left->right->left=new Node(11);
    root->right->right->left->left=new Node(9);

    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7
       
    root=leftClone(root);
    preorder(root); //1 
    cout<<endl;
    root=backToOriginal(root);
    preorder(root);
    return 0;
}