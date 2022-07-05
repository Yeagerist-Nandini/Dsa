#include<bits/stdc++.h>
using namespace std;

void buildTree(int* arr,int* tree,int start,int end,int treeNode)
{
    if(end==start)
    {
        tree[treeNode]=arr[start];
        return ;
    }

    int mid=(start+end)/2;

    buildTree(arr,tree,start,mid,treeNode*2);
    buildTree(arr,tree,mid+1,end,treeNode*2+1);

    tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];
}

void updateTree(int* arr,int* tree,int s,int e,int treeNode,int idx,int val)
{
    if(s==e)
    {
        arr[idx]=val;
        tree[treeNode]=val;
        return;
    }

    int mid=(s+e)/2;

    if(idx>mid)
    updateTree(arr,tree,mid+1,e,treeNode*2+1,idx,val);
    else
    updateTree(arr,tree,s,mid,treeNode*2,idx,val);

    tree[treeNode]=tree[treeNode*2]+tree[treeNode*2+1];
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int * tree=new int[18];

    buildTree(arr,tree,0,8,1);
    
    for(int i=1;i<=18;i++)
    cout<<tree[i]<<endl;

    return 0;
}