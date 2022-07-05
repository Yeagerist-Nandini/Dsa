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

void path(Node* root,string p)
{
    if(root==NULL)
    return;

    if(!root->left && !root->right)
    {
          cout<<p<<root->data<<endl;
          return;
    }

    path(root->left ,p +to_string(root->data) +" ");
    path(root->right,p +to_string(root->data)+" ");
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
    root->right->right->left->left=new Node(9);
    root->left->left->left=new Node(10);
    root->left->right->left=new Node(11);

    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7
       

    // preorder(root); //1 
    path(root,"");
    return 0;
}