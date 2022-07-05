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

void preorder(Node *root)
{
    cout << root->data << " ";
    for (Node *child : root->children)
        preorder(child);
}

void postorder(Node *root)
{
    for (Node *child : root->children)
        postorder(child);

    cout << root->data << " ";
}

void lTor(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        if (q.front() == NULL)
        {
            q.pop();
            if(q.size()==0)
            break;

            q.push(NULL);
            cout << endl;
        }
        else
        {
            cout << q.front()->data << " ";
            root = q.front();
            q.pop();

            for (Node *child : root->children)
            {
                q.push(child);
            }
        }
    }
}

void zigzag(Node* root)  
{
    stack<Node*> st;
    st.push(root);
    stack<Node*> h;
    int l=0;

    while(!st.empty())
    {
        root=st.top();
        st.pop();
        cout<<root->data<<" ";
        auto v=root->children;

        if(l%2==0)
        {
           for(int i=0;i<v.size();i++)
           {
               h.push(v[i]);   
           }
        }
        else
        {
            for(int i=v.size()-1;i>=0;i--)
            h.push(v[i]);
        }

        if(st.size()==0)
        {
            cout<<endl;
            st=h;
            l++;
            while (!h.empty())
            {
               h.pop();
            }            
        }  
    }
}



int main()
{
    int n;
    n = 24;
    int v[n] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = construct(v, n);
    // display(root);
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    lTor(root);
    cout << endl;
    zigzag(root);
    cout<<endl;

    return 0;
}