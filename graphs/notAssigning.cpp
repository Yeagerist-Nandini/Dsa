#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    ll n, curr=-1;
    cin >> n;

    map<int, vector<int>> l;
    vector<int> deg(n+1);
    map<pair<int, int>, int> ed;
	l.clear();
	deg.clear();
	ed.clear();

    for (int i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        l[u].push_back(v);
        l[v].push_back(u);
        ed[{u, v}] = i;
        ed[{v, u}] = i;
        deg[u]++;
        deg[v]++;
    }

	if (n == 2)
    {
        cout << 2 << endl;
        return;
    }

    for (int i = 1; i <=n; i++)
    {
        if (deg[i] > 2)
        {
            cout << -1 << endl;
            return;
        }
        if (deg[i] == 1)
            curr = i;
    }
    
	if(curr==-1)
	{
		cout<<-1<<endl;
		return;
	}

    int w = 2;
    queue<int> q;
    vector<bool> vis(n + 1, false);
    q.push(curr);
    vis[curr] = true;

    vector<int> ans(n+1);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        for (auto p : l[curr])
        {
            if (!vis[p])
            {
                vis[p] = true;
                q.push(p);

                int idx = ed[{curr, p}];
                ans[idx] = w;

                if (w == 2)
                    w = 3;
                else
                    w = 2;
            }
        }
    }

	for(int i=1;i<n;i++)
	cout<<ans[i]<<" ";
	cout<<endl;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}