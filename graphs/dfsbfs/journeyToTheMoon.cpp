#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Graphs
{
    int v;
    // list<int> *l1;
    unordered_map<T, vector<T>> l1;
    unordered_map<T, list<pair<T, int>>> l;

public:
    Graphs()
    {
        //    l1=new list<int>[v];
    }

    void addEgde(T x, T y)
    {
        l1[x].push_back(y);
        l1[y].push_back(x);
    }

    void addDirWtEgde(T x, T y, bool isBidir, int wt)
    {
        l[x].push_back({y, wt});
        if (isBidir)
        {
            l[y].push_back({x, wt});
        }
    }

    void printAdjList()
    {
        for (auto it = l1.begin(); it != l1.end(); it++)
        {
            cout << "Vertex" << it->first << "->";
            for (auto nbr : it->second)
                cout << nbr << ",";

            cout << endl;
        }
    }

    void printDirList()
    {
        for (auto p : l)
        {
            T city = p.first;
            cout << city << "->";
            auto nbrs = p.second;

            for (auto nbr : nbrs)
            {
                cout << nbr.first << " " << nbr.second << ",";
            }
            cout << endl;
        }
    }

    void BFS(T src)
    {
        vector<T> bfs;
        map<T, bool> vis;
        queue<T> q;

        for (auto p : l1)
        {
            if (vis[p.first])
                continue;

            q.push(p.first);
            vis[p.first] = true;

            while (!q.empty())
            {
                T node = q.front();
                q.pop();
                bfs.push_back(node);

                for (T nbr : l1[node])
                {
                    if (!vis[nbr])
                        q.push(nbr);

                    vis[nbr] = true;
                }
            }
        }

        for (auto it : bfs)
            cout << it << " ";
    }

    void dfs_helper(T src, map<T, bool> &vis,int &cnt)
    {
        vis[src] = true;
        cnt++;
        for (auto node : l1[src])
        {
            if (vis[node] == false)
            {
                dfs_helper(node, vis, cnt);
            }
        }
    }

    int DFS(T src)
    {
        vector<T> dfs;
        map<T, bool> vis;
        map<int,int> size;

        for (auto p : l1)
            vis[p.first] = false;

        int cnt = 0,s=0;
        for (auto p : l1)
        {
            if (!vis[p.first])
            {
                dfs_helper(p.first, vis,s);
                cnt++;
                size[cnt]=s;
                s=0;
            }
        }

        // cout<<cnt;
        // for(auto s:size)
        // cout<<s.first<<" "<<s.second<<endl;

        int ans=0;
        for(int i=1;i<=cnt;i++)
        {
            for(int j=i+1;j<=cnt;j++)
            {
                ans+=(size[i]*size[j]);
            }
        }

        return ans;
    }
};

int main()
{
    Graphs<int> g;
    // g.addEgde(2, 1);
    // g.addEgde(7, 2);
    // g.addEgde(2, 3);
    // g.addEgde(3, 5);
    // g.addEgde(5, 7);
    // g.addEgde(8, 9);
    // g.addEgde(9, 10);
    // g.addEgde(10, 8);
    // g.addEgde(10, 11);
    g.addEgde(2,1);
    g.addEgde(2,3);
    g.addEgde(0,0);


    //    g.printAdjList();
    // g.BFS(1);
    cout<<g.DFS(1);
    return 0;
}