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

Node* getTail(Node* root)
{
    while(root->children.size()==1)
    root=root->children[0];

    return root;
}

void linearize(Node* root)
{
   for(Node* child:root->children)
   linearize(child);

   while(root->children.size()>1)
   {
       Node* lc=root->children[root->children.size()-1];
       root->children.pop_back();

       Node* sl=root->children[root->children.size()-1];
       Node* slt=getTail(sl);
       slt->children.push_back(lc);
   }
}

Node* linearize2(Node* root)
{
    if(root->children.size()==0)
    return root;

    Node* lt=linearize2(root->children[root->children.size()-1]);
    
    while(root->children.size()>1)
    {
        Node* lc=root->children[root->children.size()-1];
        root->children.pop_back();

        Node* sl=root->children[root->children.size()-1];
        Node* slt=linearize2(sl);
        slt->children.push_back(lc);
    }

    return lt;
}

int main()
{
    int n;
    n = 24;
    int v[n] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = construct(v, n);
    linearize2(root);
    display(root);

    return 0;
}