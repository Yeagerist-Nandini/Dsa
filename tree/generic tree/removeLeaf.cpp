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



void removeLeaf(Node* root)
{
    for(int i=root->children.size()-1;i>=0;i--)
    {
        Node* child=root->children[i];

        if(child->children.size()==0)
        {
            root->children.erase(root->children.begin()+i);
        }
    }

    for(Node* child:root->children)
    removeLeaf(child);
}


bool find(Node* root,int val)
{
    if(root->data==val)
    return true;

    for(Node* child:root->children)
    {
        if(find(child,val))
        return true;
    }

    return false;
}

int main()
{
    int n;
    n = 24;
    int v[n] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = construct(v, n);
    cout<<find(root,23)<<find(root,110)<<endl;
    display(root);
    
    removeLeaf(root);
    display(root);

    return 0;
}