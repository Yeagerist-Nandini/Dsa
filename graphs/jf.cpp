#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, m;
int mini = INT_MAX;
char g[21][21];
bool vis[21][21];

void solve(char g[][21], bool vis[][21], int i, int j, int cnt, int path)
{
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;

    if (g[i][j] == 'x')
        return;

    if (vis[i][j])
        return;

    bool flag = false;
    if (g[i][j] == '*')
    {
        flag = true;
        cnt--;
    }

    if (cnt == 0)
    {
        mini = min(mini, path);
        return;
    }

    g[i][j] = '.';

    vis[i][j] = true;
    solve(g, vis, i + 1, j, cnt, path++);
    solve(g, vis, i, j + 1, cnt, path++);
    solve(g, vis, i - 1, j, cnt, path++);
    solve(g, vis, i, j - 1, cnt, path++);
    vis[i][j] = false;

    if (flag)
        g[i][j] = '*';
}

int main()
{
    int t;
    t = 1;
    while (t--)
    {
        cin >> m >> n;

        int id = 0, jd = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> g[i][j];
                if (g[i][j] == 'o')
                {
                    id = i;
                    jd = j;
                }
                else if (g[i][j] == '*')
                    cnt++;

                vis[i][j] = false;
            }
        }

        int ans;
        solve(g, vis, id, jd, cnt, 0);

        if (mini == INT_MAX)
            cout << -1 << endl;
        else
            cout << mini << endl;
    }

    return 0;
}

