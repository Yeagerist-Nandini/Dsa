#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graphs
{
    int v;
    // list<int> *l1;
    map<T,vector<T>> l1;

    public:
   Graphs()
   {
    //    l1=new list<int>[v];
   }

   void addEgde(T x,T y)
   {
       l1[x].push_back(y);
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
       map<T,T> parent;
       
       for(auto node:l1)
       dist[node.first]=INT_MAX;

       queue<T> q;
       q.push(src);
       dist[src]=0;
       parent[src]=src;

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
               parent[nbr]=node;
           }
       }

    //    for(auto node_pair:l1)
    //    cout<<node_pair.first<<" ans dist "<<dist[node_pair.first]<<endl;

       T temp=dest;
       while(temp!=src)
       {
           cout<<temp<<"<--";
           temp=parent[temp];
       }
       cout<<src<<endl;

       cout<<"dist "<<dist[dest]<<endl;
   }

};


int main()
{
    Graphs<int> g;
    int board[50]={0};

    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;

    for(int i=0;i<=36;i++)
    {
        for(int dice=1;dice<=6;dice++)
        {
            int j=i+dice;
            j+=board[j];

            if(j<=36)
            {
                g.addEgde(i,j);
            }
        }
    }
    g.addEgde(36,36);
    g.BFS(0,36);
    // g.printAdjList();

   return 0;
}