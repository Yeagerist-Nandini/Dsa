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

struct vpair
{
    Node* node;
    int hl;

    vpair(Node* root,int val)
    {
        node=root;
        hl=val;
    }
};


void verticalOrder(Node* root)
{
    map<int,vector<int>> mp;
    queue<vpair> q;
    int minh=0,maxh=0;

    q.push(vpair(root,0));

    while (!q.empty())
    {
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            vpair p=q.front();
            q.pop();

            minh=min(minh,p.hl);
            maxh=max(maxh,p.hl);

            mp[p.hl].push_back(p.node->data);

            if(p.node->left)
            q.push(vpair(p.node->left,p.hl-1));
            if(p.node->right)
            q.push(vpair(p.node->right,p.hl+1));
        }
    }
    
    for(auto it:mp)
    {
        cout<<it.first-minh<<"-> ";
        for(int i=0;i<it.second.size();i++)
        {
            cout<<it.second[i]<<" ";
        }
        cout<<endl;
    }
}


void top(Node* root)
{
    queue<vpair> q;
    q.push(vpair(root,0));
    map<int,int> mp; 
    set<int> s;
    
    while(!q.empty())
    {
         int size=q.size();

         for(int i=0;i<size;i++)
         {
            auto p=q.front();
            q.pop();
            
            if(s.find(p.hl)==s.end())
            mp[p.hl]=p.node->data;
            s.insert(p.hl);

            if(p.node->left)
            q.push(vpair(p.node->left,p.hl-1));
            if(p.node->right)
            q.push(vpair(p.node->right,p.hl+1));
         }
    }

    for(auto it:mp)
    cout<<it.second<<" ";
    cout<<endl;
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
    // root->right->right->right=new Node(13);
    root->right->right->left=new Node(14);
    root->left->left->left=new Node(10);
    root->left->right->left=new Node(11);
    root->right->right->left->left=new Node(9);

    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7
    verticalOrder(root);

    top(root);
    return 0;
}