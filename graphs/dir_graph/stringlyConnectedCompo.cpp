#include <bits/stdc++.h>
using namespace std;

//a dir graph is strongly connected if there is a path between all pair of vertices.
//we can visit every node from every other node
//kosaraju's Algo

void dfs(vector<int> graph[], int node, bool *vis, vector<int> &stack)
{
    vis[node] = true;
    for (auto nbr : graph[node])
    {
        if (!vis[nbr])
            dfs(graph, nbr, vis, stack);
    }

    stack.push_back(node);
}

void dfs2(vector<int> graph[], int node, bool *vis)
{
    vis[node] = true;
    cout << node << " ";
    for (auto nbr : graph[node])
    {
        if (!vis[nbr])
            dfs2(graph, nbr, vis);
    }
}

void solve(vector<int> graph[], vector<int> rev_graph[], int v)
{
    bool vis[v] = {false};
    vector<int> stack;

    //step-1 need to store the vertices acc to dfs finish time
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
            dfs(graph, i, vis, stack);
    }

    //step-2 reverse graph
    //step-3 do dfs acc to order given in stack

    for (int i = 0; i < v; i++)
        vis[i] = false;

    char compo = 'A';
    for (int x = stack.size() - 1; x >= 0; x--)
    {
        int node = stack[x];
        if (!vis[node])
        {
            cout << "component" << compo << "-->";
            dfs2(rev_graph, node, vis);
            cout << endl;
            compo++;
        }
    }
    cout<<compo;
}
 
void addEdge(vector<int> graph[],
             vector<int> rev_graph[], int x, int y)
{
    graph[x].push_back(y);
    rev_graph[y].push_back(x);
}


int main()
{
    int v;
    v = 7;
    vector<int> graph[v];
    vector<int> rev_graph[v];

    addEdge(graph, rev_graph, 1, 0);
    addEdge(graph, rev_graph, 0, 2);
    addEdge(graph, rev_graph, 0, 3);

    addEdge(graph, rev_graph, 2, 1);

    addEdge(graph, rev_graph, 5, 5);

    addEdge(graph, rev_graph, 5, 6);
    addEdge(graph, rev_graph, 6, 3);
    addEdge(graph, rev_graph, 3, 4);

    solve(graph, rev_graph, v);

    return 0;
}