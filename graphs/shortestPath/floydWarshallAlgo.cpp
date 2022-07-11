// dijkstra's =>positive edges=>greedy
// bellman ford=>negative edges=>dp
// floyd warshall=>negative edges ,can detect negative cycle =>o(n3)
// shortest between all pair of vertices for directed
// the above two are single source
// undir and dir
#include <bits/stdc++.h>
using namespace std;

#define INF 1000000

vector<vector<int>> g;

vector<vector<int>> floyd()
{
    int v = 4;
    vector<vector<int>> dist(g);


    //check for every node as an intermmediate
    for (int k = 0; k < v; k++)
    {
        // Iterate over entire 2D matrix
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                // if vertex is included ,and can we minimise the dist?
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    bool isNegativeCycle = false;

    for (int i = 0; i < v; i++)
    {
        if (dist[i][i] < 0)
            isNegativeCycle = true;
    }

    cout << isNegativeCycle << endl;

    return dist;
}

int main()
{
    g={
        {0,INF,-2,INF},
        {4,0,3,INF},
        {INF,INF,0,2},
        {INF,-1,INF,0}
    };

    // g = {
    //     {0, 1, INF, INF},
    //     {INF, 0, -1, INF},
    //     {INF, INF, 0, -1},
    //     {-1, INF, INF, 0}};

    vector<vector<int>> sPath = floyd();

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << sPath[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}