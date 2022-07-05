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


bool nTorPath(Node* root,int val,vector<int> &v)
{
    if(root->data==val)
    {
        v.push_back(val);
        return true;
    }

    for(Node* child:root->children)
    {
        if(nTorPath(child,val,v))
        {
            v.push_back(root->data);
            return true;
        }
    }

    return false;
}

int LCA(Node* root,int e1,int e2)
{
    vector<int> v1,v2;
    nTorPath(root,e1,v1);
    nTorPath(root,e2,v2);

    int i=v1.size()-1,j=v2.size()-1;
    while(i>=0 && j>=0 && v1[i]==v2[j])
    {
        i--;
        j--;
    }

    i++;
    j++;
    return v1[i];
}


int dist2nodes(Node* root,int e1,int e2)
{
    vector<int> v1,v2;
    nTorPath(root,e1,v1);
    nTorPath(root,e2,v2);

    int i=v1.size()-1,j=v2.size()-1;
    while(i>=0 && j>=0 && v1[i]==v2[j])
    {
        i--;
        j--;
    }

    i++;
    j++;
    
    int dist=i+j;
    return dist;
}

int main()
{
    int n;
    n = 24;
    int v[n] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = construct(v, n);
    // cout<<find(root,23)<<find(root,110)<<endl;
    // display(root);
    
    vector<int> arr;

    nTorPath(root,110,arr);
    for(int i=0;i<arr.size();i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    cout<<LCA(root,70,110)<<endl;
    cout<<dist2nodes(root,70,70);

    return 0;
}