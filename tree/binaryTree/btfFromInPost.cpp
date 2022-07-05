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


vector<int> pr;
vector<int> in;
vector<int> po;
//  left hota h 
void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    pr.push_back(root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
   
    postorder(root->left);
    postorder(root->right);
    po.push_back(root->data);
}

void pre(Node* root)
{
    if(root==NULL)
    {
        return;
    }
   
    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}

void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    inorder(root->left);
    in.push_back(root->data);
    inorder(root->right);
}

Node* inpost(vector<int> post,vector<int> in,int psi,int pei,int isi,int iei)
{
    if(isi>iei)
    return NULL;

    Node* node=new Node(post[pei]);
    int i=isi;

    while(in[i]!=post[pei]) i++;
    int t=i-isi;

    node->left=inpost(post,in,psi,psi+t-1,isi,i-1);
    node->right=inpost(post,in,psi+t,pei-1,i+1,iei);

    return node;
}


Node* inpre(vector<int> pre,vector<int> in,int psi,int pei,int isi,int iei)
{
    if(isi>iei)
    return NULL;

    Node* node=new Node(pre[psi]);
    int i=isi;

    while(in[i]!=pre[psi]) i++;
    int t=i-isi;

    node->left=inpre(pre,in,psi+1,psi+t,isi,i-1);
    node->right=inpre(pre,in,psi+t+1,pei,i+1,iei);

    return node;
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
       

    preorder(root); //1 
    inorder(root);
    postorder(root);
    
    Node* node=inpre(pr,in,0,po.size()-1,0,in.size()-1);

    pre(root);
    cout<<endl;
    pre(node);
    
    return 0;
}