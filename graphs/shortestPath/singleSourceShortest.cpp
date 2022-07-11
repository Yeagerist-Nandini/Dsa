#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graphs
{
    int v;
    // list<int> *l1;
    unordered_map<T,vector<T>> l1;

    public:
   Graphs()
   {
    //    l1=new list<int>[v];
   }

   void addEgde(T x,T y)
   {
       l1[x].push_back(y);
       l1[y].push_back(x);
   }


   void printAdjList()
   {
       for(auto it=l1.begin();it!=l1.end();it++)
       {
           cout<<"Vertex"<<it->first<<"->";
           for(auto nbr:it->second)
           cout<<nbr<<",";

           cout<<endl;
       }
   }

   
   void BFS(T src,T dest)
   {
       map<T,int> dist;
       for(auto node:l1)
       dist[node.first]=INT_MAX;

       queue<T> q;
       q.push(src);
       dist[src]=0;

       while(!q.empty())
       {
           T node=q.front();
           q.pop();

           for(T nbr:l1[node])
           {
               if(dist[nbr]!=INT_MAX)
               continue;

               q.push(nbr);
               dist[nbr]=dist[node]+1;
           }
       }

       cout<<dist[dest]<<" ";
   }
   //dist calc by level order traversal is the shortest

};


int main()
{
    Graphs<int> g;
    g.addEgde(2,1);
    g.addEgde(7,2);
    g.addEgde(2,3);
    g.addEgde(3,5);
    g.addEgde(5,7);

   g.printAdjList();
   g.BFS(1,5);

   return 0;
}