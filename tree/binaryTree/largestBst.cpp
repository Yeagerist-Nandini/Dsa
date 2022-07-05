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

struct bstPair{
    bool isbst;
    int min;
    int max;
    Node* root;
    int size;
};

bstPair isBst(Node* root)
{
    if(root==NULL)
    {
        bstPair mp;
        mp.isbst=true;
        mp.min=INT_MAX;
        mp.max=INT_MIN;
        mp.size=0;
        mp.root=NULL;
        return mp;
    }

    bstPair lp=isBst(root->left);
    bstPair rp=isBst(root->right);

    bstPair mp;
    mp.isbst=lp.isbst && rp.isbst && (root->data<=rp.min && root->data>=lp.max);
    mp.max=max({root->data,rp.max,lp.max});
    mp.min=min({root->data,rp.min,lp.min});

    if(mp.isbst)
    {
        mp.size=lp.size+rp.size+1;
        mp.root=root;
    }
    else if(lp.size>rp.size)
    {
        mp.size=lp.size;
        mp.root=lp.root;
    }
    else
    {
        mp.size=rp.size;
        mp.root=rp.root;
    }

    return mp;
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
    auto m=isBst(root);
    cout<<m.size<<" "<<m.root->data;
    return 0;
}