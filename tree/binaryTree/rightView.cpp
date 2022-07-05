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

void rightVeiw(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    { 
        int size=q.size();

        for(int i=0;i<size;i++)
        {
            root=q.front();
            if(i==size-1)
            {
                cout<<q.front()->data<<" ";
            }
            
            if(root->left)
            q.push(root->left);
            if(root->right)
            q.push(root->right);
            q.pop();
        }
    }
}

void leftView(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    { 
        int size=q.size();

        for(int i=0;i<size;i++)
        {
            root=q.front();
            if(i==0)
            {
                cout<<q.front()->data<<" ";
            }
            
            if(root->left)
            q.push(root->left);
            if(root->right)
            q.push(root->right);
            q.pop();
        }
    }
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
       

    // preorder(root); //1 
    rightVeiw(root);
    return 0;
}