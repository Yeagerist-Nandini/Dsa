// Disjoint Union Set (DSU)
// Union -Find
//to minimize the time complexity we compressed the path
//In union func we have to find the parent by travesing all over the path 
//Instead we can just connect the every node to its super parent so that we dont have to traverse agsin and again
//TC=>O(4*alpha)~O(4);

#include <bits/stdc++.h>
using namespace std;

// find=>returns leader of the set that contain the ele v 
//this representative is used to check if a and b are part of the same set 
// union =>merge 2 sets into one

class dsu
{
    int *parent;
    int *rank;
    int n;

public:
    dsu(int n)
    {
        this->n = n;
        parent=new int[n+1];
        rank=new int[n+1];

        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }

    int findPar(int node)
    {
        if(node==parent[node])
        return node;

        return parent[node]=findPar(parent[node]);       //path compression
    }

    void union_set(int s1, int s2)
    {
         s1 = findPar(s1);
         s2 = findPar(s2);

        if(rank[s1]<rank[s2])
        parent[s1]=s2;
        else if(rank[s1]>rank[s2])
        parent[s2]=s1;
        else{
            parent[s2]=s1;
            rank[s1]++;
        }

    }

    void display()
    {
        for(int i=1;i<=n;i++)
        cout<<parent[i]<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++)
        cout<<rank[i]<<" ";
    }

};

int main()
{
    dsu d(7);
    d.union_set(1,2);
    d.union_set(2,3);
    d.union_set(4,5);
    d.union_set(6,7);
    d.union_set(3,7);
    d.union_set(5,6);
    d.display();
    if(d.findPar(2)!=d.findPar(3))
    cout<<"Different Component";
    else
    cout<<"SAME";

    return 0;
}