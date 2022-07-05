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

Node *construct(int arr[], int n)
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

void display(Node *root)
{
    cout << root->data << "-> ";
    for (Node *child : root->children)
    {
        cout << child->data << ", ";
    }
    cout << "." << endl;

    for (Node *child : root->children)
        display(child);
}

bool similar(Node* r1,Node* r2)
{
    if(r1->children.size()!=r2->children.size())
    return false;

    for(int i=0;i<r1->children.size();i++)
    {
        if(!similar(r1->children[i],r2->children[i]))
        return false;
    }

    return true;
}

int main()
{
    int n;
    n = 24;
    int v[n] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = construct(v, n);
    
    int arr[]={10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80,120,-1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root1=construct(arr,22);
    cout<<similar(root,root1);

    return 0;
}