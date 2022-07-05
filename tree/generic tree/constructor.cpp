#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

Node *newNode(int val)
{
    Node *node = new Node;
    node->data = val;
    return node;
}

Node* construct(int arr[], int n)
{
    Node *root = NULL;
    stack<Node *> st;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
            st.pop();
        else
        {
            Node *t = newNode(arr[i]);
            if (st.size() == 0)
                root = t;
            else
                st.top()->children.push_back(t);
            st.push(t);
        }
    }
    return root;
}

void display(Node* root)
{
     cout<<root->data<<"-> ";
     for(Node* child:root->children)
     {
         cout<<child->data<<", ";
     }
     cout<<"."<<endl;

     for(Node* child:root->children)
     display(child);
}

int size(Node* root)
{
    if(root->children.size()==0)
    return 1;

    int s=0;
    for(Node* child:root->children)
    {
        s+=size(child);
    }

    s++;
    return s;
}

int maximum(Node* root)
{
    if(root->children.size()==0)
    return root->data;

    int maxi=root->data;
    for(Node* child:root->children)
    {
       maxi=max(maximum(child),maxi); 
    }

    return maxi;
}

int height(Node* root)
{
    if(root->children.size()==0)
    return 1;

    int maxi=INT_MIN;
    for(Node* child:root->children)
    {
        int h=height(child);
        maxi=max(maxi,h);
    }

    maxi++;
    return maxi;
}


int main()
{
    int n;
    n=24;
    int v[n]={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    Node* root=construct(v,n);
    // display(root);
    cout<<size(root)<<" "<<maximum(root)<<endl;
    cout<<height(root)<<endl;
    
    return 0;
}