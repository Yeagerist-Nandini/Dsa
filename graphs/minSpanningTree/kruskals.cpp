// Min Spanning Tree
// spanning tree=> connects all vertices of the graph with no cycle (v nodes then v-1 edges)(single connected component)
// subset of edges such that it forms a tree that connects all vertices of the graph
// and have minimum cost(min sum of the wts) with no cycle

// kruskal => greedy algo

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graphs
{
    int v;
    vector<vector<int>> l;

public:
    Graphs(int v)
    {
        this->v = v;
    }

    void addEdge(int a, int b, int wt)
    {
        l.push_back({wt, a, b});
    }

    int minSpanning()
    {
        sort(l.begin(), l.end());

        DSU s(v);

        int ans = 0;
        for (auto edge : l)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
            }
        }

        return ans;
    }
};

int main()
{
    int v, m;
    // cin>>v>>m;
    v = 4;

    Graphs g(v);

    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);

    cout << g.minSpanning();
    return 0;
}