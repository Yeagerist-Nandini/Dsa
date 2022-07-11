// Min Spanning Tree
// spanning tree=> connects all vertices of the graph with no cycle (v nodes then v-1 edges)(single connected component)
// subset of edges such that it forms a tree that connects all vertices of the graph 
//and have minimum cost(min sum of the wts) with no cycle


//prim => greedy algo 
//mst set=[]
//active edge = edge from a vertex in mst set to v
//mst edge= an egde that has been included in mst so far

//1. start from any src vertex
//2.out of all active edge ,pick one with smallest wt
//select in y in mst
//add edge starting fron y in the active edge list



#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;



class Graphs
{
    int v;
    list<pair<int,int>> *l;

public:
    Graphs(int v)
    {
        this->v = v;
        l=new list<pair<int,int>>[v];
    }

    void addEdge(int a, int b, int wt)
    {
        l[a].push_back({b,wt});
        l[b].push_back({a,wt});
    }

    int prim()
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;

        bool* vis=new bool[v]{0};
        int ans=0;

        q.push({0,0});
        while(!q.empty())
        {
            auto best=q.top();
            q.pop();

            int to=best.second;
            int wt=best.first;

            if(vis[to])
            continue;

            ans+=wt;
            vis[to]=true;

            for(auto nbr:l[to])
            {
                if(vis[nbr.first]==0)
                q.push({nbr.second,nbr.first});
            }
        }

        return ans;
    }
};

int main()
{
    int v,m;
    // cin>>v>>m;
    v=4;

    Graphs g(v);

    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);

    cout<<g.prim();
    return 0;
}