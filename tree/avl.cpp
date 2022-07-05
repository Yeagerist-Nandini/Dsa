#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left = NULL;
    Node *right = NULL;
    int h = 0;
    int bal = 0;

    Node(int v)
    {
        val = v;
    }
};

void updateHeightandBal(Node *root)
{
    int lh = -1; // if null
    int rh = -1;

    if (root->left)
        lh = root->left->h;
    if (root->right)
        rh = root->right->h;

    int bal = lh - rh;
    int height = max(lh, rh) + 1;

    root->h = height;
    root->bal = bal;
}

Node *rightrotation(Node *A)
{
    Node *B = A->left;
    Node *Bright = B->right;

    B->right = A;
    A->left = Bright;

    updateHeightandBal(A);
    updateHeightandBal(B);

    return B;
}

Node *leftrotation(Node *A)
{
    Node *B = A->right;
    Node *Bleft = B->left;

    B->left = A;
    A->right = Bleft;

    updateHeightandBal(A);
    updateHeightandBal(B);

    return B;
}

Node *getRotation(Node *root)
{
    updateHeightandBal(root);

    if (root->bal == 2) // ll,lr
    {
        if (root->left->bal == 1) // ll
            return rightrotation(root);
        else if (root->left->bal == -1) // lr
        {
            root->left = leftrotation(root->left);
            return rightrotation(root);
        }
    }
    else if (root->bal == -2) // rr,rl
    {
        if (root->right->bal == -1) // rr
            return leftrotation(root);
        else if (root->right->bal == 1) // rl
        {
            root->right = rightrotation(root->right);
            return leftrotation(root);
        }
    }

    return root;
}

Node *addData(Node *root, int data)
{
    if (root == NULL)
        return new Node(data);

    if (root->val > data)
        root->left = addData(root->left, data);
    else
        root->right = addData(root->right, data);

    return getRotation(root); 
}

int maxi(Node* root)
{
    while(root->right)
    root=root->right;

    return root->val;
}

Node *remove(Node *root, int data)
{
    if(root==NULL)
    return NULL;

    if(data<root->val)
    root->left=remove(root->left,data);
    else if(data>root->val)
    root->right=remove(root->right,data);
    else
    {
        if(!root->left && !root->right)
        return NULL;
        else if(!root->left)
        return root->right;
        else if(!root->right)
        return root->left;
        else
        {
            int lmax=maxi(root->left);
            root->val=lmax;
            root->left=remove(root->left,lmax);
        }
    }

    return getRotation(root);
}

void display(Node *root)
{
    if (root == NULL)
        return;

    if (root->left)
        cout << root->left->val;
    else
        cout << '.';

    cout << "<-";
    cout << root->val;
    cout << "->";
    if (root->right)
        cout << root->right->val;
    else
        cout << '.';

    cout << endl;

    display(root->left);
    display(root->right);
}

void solve()
{
    int arr[] = {10, 20, 30, 40, 60, 70, 50, 90, 80, 100};
    Node *root = NULL;

    for (int i = 0; i < 10; i++){
        root = addData(root, arr[i]);
        // cout<<root->h<<" "<<root->bal<<endl;
    }
    display(root);
    remove(root,80);
    display(root);
}

int main()
{
    solve();
    return 0;
}