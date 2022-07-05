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

struct Pair
{
   int second;
   Node* first;

   Pair(Node* root,int val)
   {
       first=root;
       second=val;
   }

};

void iterative(Node* root)
{
    stack<Pair> st;
    Pair p(root,1);

    st.push(p);
    
    string pre="",post="",in="";

    while(!st.empty())
    {
        auto p=st.top();
        if(p.second==1)
        {
            pre+=p.first->data;
            p.second++;
            if(p.first->left)
            {
                Pair t(p.first->left,1);
                st.push(t);
            }
        }
        else if(p.second==2)
        {
            in+=p.first->data;
            p.second++;
            if(p.first->right)
            {
                Pair t(p.first->right,1);
                st.push(t);
            }
        }
        else if(p.second==3)
        {
            post+=p.first->data;
            st.pop();
        }
    }

    cout<<pre<<" "<<in<<" "<<post<<endl;
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
    iterative(root);
    return 0;
}