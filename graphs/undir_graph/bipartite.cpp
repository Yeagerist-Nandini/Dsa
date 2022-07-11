#include<bits/stdc++.h>
using namespace std;

//we can divide all vertices if graph in 2 sets such that all the edges of the graph are from set1 to set2
//all the alternate nodes should not have same color 
//A TREE is a bipartite graph (odd level belongs to one set and even level belongs to other set)

//Not Bipartite
//If a graph has a cycle and has odd no of nodes

class Graphs
{
    int v;
    list<int> *l;
    public:
    Graphs(int v)
    {
        this->v=v;
        l=new list<int>[v];
    }

    void addEgde(int x,int y)
   {
       l[x].push_back(y);
       l[y].push_back(x);
   }

   bool cycle_helper(int node,int* vis,int parent,int color)
   {
       vis[node]=color;

       for(auto nbr:l[node])
       {
           if(!vis[nbr])
           {
               bool cycle=cycle_helper(nbr,vis,node,3-color);
               if(!cycle)
               return false;
           }
           else if(nbr!=node && color==vis[nbr])
           return false;
       }

       return true;
   }

   bool isBipartite()
   {
    int* vis=new int(v);
    for(int i=0;i<v;i++)
    vis[i]=0;

    bool cycle =cycle_helper(0,vis,-1,1);
    for(int i=0;i<v;i++)
    cout<<vis[i]<<" ";
    cout<<endl;

    return cycle;
   }  
};

int main()
{
    Graphs g(5);
    g.addEgde(0,1);
    g.addEgde(0,2);
    g.addEgde(1,3);
    g.addEgde(2,4);
    g.addEgde(3,2);
    g.addEgde(3,4);

    cout<<g.isBipartite();
}