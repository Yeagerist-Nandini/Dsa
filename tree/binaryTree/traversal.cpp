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

void display(Node* root)
{
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}



// left se aane k baad right m jaaane se phle 
void inorder(Node* root)
{
    if(root==NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// phle left right then between 
void postorder(Node* root)
{
    if(root==NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


void levelOrder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            q.pop();

            if(q.size()==0)
            break;

            q.push(NULL);
            cout<<endl;
        }
        else
        {
            cout<<q.front()->data<<" ";
            root=q.front();
            q.pop();

            if(root->left)
            q.push(root->left);
            if(root->right)
            q.push(root->right);
        }
    }
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

    //     1
    //    / \
    //   2   3
    //  / \ / \
    // 4  5 6  7 

    // preorder(root); //1 2 4 5 3 6 7
    // inorder(root);  //4 2 5 1 6 3 7
    // postorder(root); //4 5 2 6 7 3 1 

    levelOrder(root);
    return 0;
}