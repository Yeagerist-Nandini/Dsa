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

void Iterative(Node* root)
{
    stack<pair<Node*,int>> st;
    string pre="";
    string pos="";
    st.push({root,-1});

    while(!st.empty())
    {
        auto t=st.top();

        if(t.second==-1)
        {
            pre+=t.first->data+" ";
            t.second++;
        }
        else if(t.second==t.first->children.size())
        {
            pos+=t.first->data+" ";
            st.pop();
        }
        else
        {
            auto cp=make_pair(t.first->children[t.second],-1);

            st.push(cp);

            t.second++;
        }
    }

    cout<<pre<<"  "<<pos<<endl;
}

int main()
{
    int n;
    n = 24;
    int v[n] = {10, 20, -50, -1, -60, -1, -1, 30, -70, -1, 80, -110, -1, 120, -1, -1, 90, -1, -1, 40, -100, -1, -1, -1};
    Node *root = construct(v, n);
    Iterative(root);
    
    return 0;
}