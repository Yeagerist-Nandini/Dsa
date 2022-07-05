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

bool find(Node* root,int val)
{
    if(root==NULL)
    return false;

    if(root->data==val)
    return  true;

    if(root->left)
    {
       if(find(root->left,val))
       return true;       
    }

    if(root->right)
    {
        if(find(root->right,val))
        return true;
    }    

    return false;
}

vector<int> path;
bool NodeToRootPath(Node* root,int val)
{
   if(root==NULL)
   return false;

   if(root->data==val)
   {
       path.push_back(root->data);
       return true;
   }

   if(NodeToRootPath(root->left,val))
   {
       path.push_back(root->data);
       return true;
   }

   if(NodeToRootPath(root->right,val))
   {
       path.push_back(root->data);
       return true;
   }

   return false;
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
    NodeToRootPath(root,5);
    for(int i=0;i<path.size();i++)
    cout<<path[i]<<" ";

    return 0;
}