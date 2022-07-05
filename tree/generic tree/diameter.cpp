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

int di=0;
int dia(Node* root)
{
    int h1=-1,h2=-1;
    for(Node* child:root->children)
    {
        int h=dia(child);
        if(h>h1)
        {
            h2=h1;
            h1=h;
        }
        else if(h>h2)
        {

            h2=h;
        }
    }

    int d=h1+h2+2;
    if(d>di)
    {
        di=d;
    }

    return h1+1;
}              


int main()
{
    int n;
    n = 24;
    int v[n] = {10, 20, -50, -1, -60, -1, -1, 30, -70, -1, 80, -110, -1, 120, -1, -1, 90, -1, -1, 40, -100, -1, -1, -1};
    Node *root = construct(v, n);
    dia(root);
    cout<<di;
    
    return 0;
}







