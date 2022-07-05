#include<bits/stdc++.h>
using namespace std;

//if topo sort =>dag=>no cycle=>kahns algo

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


    //if the nbr of the node is already visited and it is in current path means it forms cycle
    //0->1->2->5->3->4->2

    bool dfs_helper(int node,vector<bool> &vis,vector<bool> &current_path)
    {
        vis[node]=true;
        current_path[node]=true;
        for(auto nbr:l[node])
        {
            if(!vis[nbr])
            {
                if(dfs_helper(nbr,vis,current_path))
                return true;
            }
            else if(current_path[nbr]==true)
            return true;
        }

        current_path[node]=false;        
        return false;
    }
    bool cycleDFS()
    {
        vector<bool> vis(v+1,false);
        vector<bool> current_path(v+1,false);

        bool cycle=false;

        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            // cycle=cycle||dfs_helper(i,vis,current_path);
            if(dfs_helper(i,vis,current_path))
            return true;
        }
        return cycle;
    }


    bool cycleBFS()
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
        
        
        for(auto it:topo)
        {
            cout<<it<<" ";
        }

        if(topo.size()!=v)
        return 1;
        return 0;
    }
};


int main()
{
    Graphs g(7);
    g.addEgde(0,1);
    g.addEgde(1,5);
    g.addEgde(1,2);
    g.addEgde(3,4);
    g.addEgde(4,5);
    g.addEgde(5,6);
    g.addEgde(4,2);
    g.addEgde(2,3);

    cout<<g.cycleDFS()<<endl;
    cout<<g.cycleBFS()<<endl;
    return 0;
}