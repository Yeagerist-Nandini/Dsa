#include<bits/stdc++.h>
using namespace std;

//if the nbrs of any node is already vis during the traversal ans its not the parent of the curr node then 
//we can say that a cylce is present in the graph

template<typename T>

class Graphs
{
    int v;
    list<int> *l1;

    public:
   Graphs(int v)
   {
       this->v=v;
       l1=new list<int>[v+1];
   }

   void addEgde(T x,T y)
   {
       l1[x].push_back(y);
       l1[y].push_back(x);
   }
     

   bool dfs_helper(T src,bool* vis,T parent)
   {
       vis[src]=true;
       for(auto node:l1[src])
       {
           if(vis[node]==false)
           {
               bool cycle=dfs_helper(node,vis,src);
               if(cycle)
               return true;
           }
           else{
               if(node!=parent)
               return true;
           }
       }

       return false;
   }


   bool isCycle()
   {
       bool *vis=new bool[v+1];
       for(int i=1;i<=v;i++)
       vis[i]=false;

       bool cycle=false;
       for(int i=1;i<=v;i++)
       {
           if(!vis[i])
           cycle=cycle || dfs_helper(i,vis,-1);
       }

    return cycle;
   }

   void bfs(int src,int n,int &ans)
   {
       vector<int> dist(n+1,INT_MAX);
       queue<int> q;
       q.push(src);
       dist[src]=0;

       while(!q.empty())
       {
           int curr=q.front();
           q.pop();

           for(auto nbr:l1[curr])
           {
               if(dist[nbr]==INT_MAX)
               {
                   q.push(nbr);
                   dist[nbr]=dist[curr]+1;
               }
               else if(dist[nbr]>=dist[curr])
               {
                  ans=min(ans,dist[nbr]+dist[curr]+1);
               }
           }
       }
   }

   void shortestCycle()
   {
       int n=v;
       int ans=n+1;
       for(int i=1;i<=n;i++)
       {
           bfs(i,n,ans);
       }

       if(ans==n+1)
       cout<<"no cycle"<<endl;
       else
       cout<<"shortest cycle lenght "<<ans<<endl;
   }
};

//wherever the back edge will be found between any two nodes while doing a bfs then there will be a cycle
//if we have to find the correct lenght of all the cycle we have to start with the node present in the both cycle
//otherwise the lenght may not be correct. we have to find lenght of all the cycle in the graph

int main()
{
    Graphs<int> g(5);
    g.addEgde(1,2);
    g.addEgde(1,3);
    g.addEgde(2,4);
    g.addEgde(2,5);
    g.addEgde(4,5);
    g.addEgde(5,3);
  
    cout<<g.isCycle()<<endl;
    g.shortestCycle();
   return 0;
}