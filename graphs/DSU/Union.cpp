// Disjoint Union Set (DSU)
// Union -Find
//-cycle in an undirected ->kruskal's Algo
//tells us if some component belongs to same or other component

#include <bits/stdc++.h>
using namespace std;

// find=>set of the node
// union =>merge 2 sets into one

class dsu
{
    list<pair<int, int>> l;
    int n;

public:
    dsu(int n)
    {
        this->n = n;
    }

    void addEdge(int u, int v)
    {
        l.push_back({u, v});
    }

    int find(int i, int *parent)
    {
        if (parent[i] == -1)
            return i;

        return find(parent[i], parent);
    }

    void union_set(int a, int b, int *parent)
    {
        int s1 = find(a, parent);
        int s2 = find(b, parent);

        if (s1 != s2)
            parent[s1] = s2;
    }

    bool isCycle()
    {
        int *parent = new int[n + 1];
        for (int i = 1; i <= n; i++)
        {
            parent[i] = -1;
        }

        for (auto edge : l)
        {
            int i = edge.first;
            int j = edge.second;

            int s1 = find(i, parent);
            int s2 = find(j, parent);

            if (s1 != s2)
                union_set(s1, s2, parent);
            else
                return true;
        }

        delete [] parent;
        return false;
    }
};

int main()
{
    dsu d(7);
    d.addEdge(1,2);
    d.addEdge(2,3);
    d.addEdge(4,5);
    d.addEdge(6,7);
    d.addEdge(3,7);
    d.addEdge(5,6);

    cout<<d.isCycle();

    return 0;
}