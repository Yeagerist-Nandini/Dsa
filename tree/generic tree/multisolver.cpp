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

int size,mini,maxi,height;


//travel and change strategy
void multisolver(Node* root,int depth)
{
    size++;
    mini=min(mini,root->data);
    maxi=max(maxi,root->data);
    height=max(height,depth);

    for(Node* child:root->children)
    {
        multisolver(child,depth+1);
    }
}

//predecessor and successor
int state,predecessor,successor;

void pre(Node* root,int data)
{
    if(state==0)
    {
        if(root->data==data)
        state=1;
        else
        predecessor=root->data;
    }
    else if(state==1)
    {
        successor=root->data;
        state=2;
    }

    for(Node* child:root->children)
    {
        pre(child,data);
    }
}

int main()
{
    int n;
    n = 24;
    int v[n] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = construct(v, n);
    size=0;
    mini=INT_MAX;
    maxi=INT_MIN;
    height=0;   
   
    multisolver(root,0);
    cout<<size<<" "<<mini<<" "<<maxi<<" "<<height<<endl;

    state=0;
    pre(root,90);
    cout<<predecessor<<" "<<successor<<endl;
    
    return 0;
}