#include <bits/stdc++.h>
using namespace std;

char graph[21][21];
int dist[21][21];
int final_graph[21][21];

int row[] = {-1, 1, 0, 0};
int col[] = {0, 0, -1, 1};

int tsp(int src, int n, int mask)
{
    if (mask == 0)
        return 0;

    int ret = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
            ret = min(ret, tsp(i, n, (mask ^ (1 << i))) + final_graph[src][i]);
    }
    return ret;
}

void bfs(int x, int y, int n, int m)
{
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 21; j++)
            dist[i][j] = INT_MAX;

    queue<pair<int, int>> q;
    dist[x][y] = 0;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        pair<int, int> f = q.front();
        q.pop();
        int x = f.first;
        int y = f.second;
        for (int i = 0; i < 4; i++)
        {
            if (x + row[i] >= 0 && x + row[i] < n && y + col[i] >= 0 && y + col[i] < m && graph[x + row[i]][y + col[i]] != 'x' && dist[x + row[i]][y + col[i]] == INT_MAX)
            {
                dist[x + row[i]][y + col[i]] = 1 + dist[x][y];
                q.push(make_pair(x + row[i], y + col[i]));
            }
        }
    }
}
int main()
{
    while (1)
    {
        int n, m;
        cin >> m >> n;

        if (n == 0 && m == 0)
            break;

        vector<pair<int, int>> dirty;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> graph[i][j];
                if (graph[i][j] == 'o' || graph[i][j] == '*')
                    dirty.push_back(make_pair(i, j));
                final_graph[i][j] = INT_MAX;
            }
        }

        int possible = 1;

        int src;

        for (int i = 0; i < dirty.size(); i++)
        {
            int x = dirty[i].first;
            int y = dirty[i].second;
            if (graph[x][y] == 'o')
                src = i;
            bfs(x, y, n, m);
            for (int j = 0; j < dirty.size(); j++)
            {
                final_graph[i][j] = dist[dirty[j].first][dirty[j].second];
                if (final_graph[i][j] == INT_MAX)
                {
                    possible = 0;
                    cout << -1 << endl;
                    break;
                }
            }
            if (!possible)
                break;
        }

        if (possible)
        {
            int n = dirty.size(); // no of nodes
            int mask = ((1 << n) - 1);
            mask = (mask ^ (1 << src)); //remove starting location from mask
            //cout<<"mask="<<mask<<endl;
            cout << tsp(src, n, mask) << endl;
        }
    }
}
