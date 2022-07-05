#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graphs
{
    int v;
    list<pair<int,int>> *l1;

public:
    Graphs(int v)
    {
        this->v=v;
        l1=new list<pair<int,int>>[v];
    }

    void addDirWtEgde(T x, T y,int wt)
    {
        l1[x].push_back({y, wt});
        l1[y].push_back({x, wt});
    }


    void printDirList()
    {
        for(int i=0;i<v;i++)
        {
            cout<<i<<endl;
            for(auto nbr:l1[i])
            {
                cout<<nbr.first<<" "<<nbr.second<<endl;
            }
        }
    }


    int dfs_helper(int node,bool* vis,int* cnt,int &ans)
    {
        vis[node] = true;
        cnt[node]=1;
        for (auto node_pair : l1[node])
        {
            int nbr=node_pair.first;
            int wt=node_pair.second;
            if (vis[nbr] == false)
            {
               cnt[node]+=dfs_helper(nbr,vis,cnt,ans);
               int nx=cnt[nbr];
               int ny=v-nx;
               ans+=2*min(nx,ny)*wt;
            }
        }

        return cnt[node];
    }

    int DFS()
    {
        bool *vis=new bool[v];
        int *cnt=new int[v];

        for(int i=0;i<v;i++)
        {
            vis[i]=false;
            cnt[i]=0;
        }

        int ans = 0;
        dfs_helper(0,vis,cnt,ans);

       return ans;
    }
};

int main()
{
    // int t;
    // cin>>t;
    // while(t--)
    // {
    //     int n;
    //     cin>>n;

    //     Graphs<int> g(n);

    //     for(int i=1;i<n;i++)
    //     {
    //         int x,y,z;
    //         cin>>x>>y>>z;
    //         g.addDirWtEgde(x,y,z);
    //     }

    //     g.DFS();
    // }

    Graphs<int> g(4);
    g.addDirWtEgde(0,1,3);
    g.addDirWtEgde(1,2,2);
    g.addDirWtEgde(2,3,2);
    cout<<g.DFS()<<endl;
    g.printDirList();
    
    return 0;
}