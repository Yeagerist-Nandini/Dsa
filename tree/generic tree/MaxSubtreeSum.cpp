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


int maxi,maxin=0;
int maxSum(Node* root)
{
    int s=0;
    for(Node* child:root->children)
    {
        s+=maxSum(child);
    }
    
    s=s+root->data;
    if(maxi<s)
    {
        maxi=s;
        maxin=root->data;
    }

    return s;
}

int main()
{
    int n;
    n = 24;
    int v[n] = {10, 20, -50, -1, -60, -1, -1, 30, -70, -1, 80, -110, -1, 120, -1, -1, 90, -1, -1, 40, -100, -1, -1, -1};
    Node *root = construct(v, n);
    maxi=INT_MIN;
    maxSum(root);
    cout<<maxi;
    
    return 0;
}