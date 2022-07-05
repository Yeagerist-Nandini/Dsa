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


void kLevel(Node* root,int k,Node* blocker)
{
    if(root==NULL || k<0 || root==blocker)
    return ;

    if(k==0)
    cout<<root->data<<" ";

    kLevel(root->left,k-1,blocker);
    kLevel(root->right,k-1,blocker);
}

vector<Node*> path;
bool NodeToRootPath(Node* root,int val)
{
   if(root==NULL)
   return false;

   if(root->data==val)
   {
       path.push_back(root);
       return true;
   }

   if(NodeToRootPath(root->left,val))
   {
       path.push_back(root);
       return true;
   }

   if(NodeToRootPath(root->right,val))
   {
       path.push_back(root);
       return true;
   }

   return false;
}

void kNodesFar(Node* root,int k,int val)
{
    NodeToRootPath(root,val);

    for(int i=0;i<path.size();i++)
    {
        kLevel(path[i],k-i, (i==0)?NULL:path[i-1]);
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

    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7
       

    // preorder(root); //1 2 4 5 3 6 7
    kNodesFar(root,2,6);
    return 0;
}