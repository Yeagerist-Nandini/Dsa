#include<bits/stdc++.h>
using namespace std;

//Topological sort
//A linear ordering of its vertices such that for every directed edge uv form vertex u to vertex v,
// u comes before v in the ordering 

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
    }

    void dfs_helper(int node,vector<bool> &vis,stack<int> &st)
    {
        vis[node]=true;
        for(auto nbr:l[node])
        {
            if(!vis[nbr])
            {
                dfs_helper(nbr,vis,st);
            }
        }
        st.push(node);
    }
    void DFS()
    {
        vector<bool> vis(v+1,false);
        stack<int> st;
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            dfs_helper(i,vis,st);
        }
        

        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
    }


    void BFS()
    {
        queue<int> q;
        vector<bool> vis(v+1,false);
        
        vector<int> inDeg(v,0);
        for(int i=0;i<v;i++)
        {
            for(auto it:l[i])
            inDeg[it]++;
        }
        vector<int> topo;

        for(int i=0;i<v;i++)
        if(inDeg[i]==0)
        q.push(i);

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(auto p:l[node])
            {
                inDeg[p]--;
                if(inDeg[p]==0)
                q.push(p);
            }
        }

        if(topo.size()!=v)
        {
            cout<<"cycle";
            return;
        }

        for(auto it:topo)
        {
            cout<<it<<" ";
        }
    }
};


int main()
{
    Graphs g(6);
    g.addEgde(5,0);
    g.addEgde(4,0);
    g.addEgde(4,1);
    g.addEgde(5,2);
    g.addEgde(2,3);
    g.addEgde(3,1);

    g.DFS();
    g.BFS();

    return 0;
}