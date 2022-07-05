#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct player
{
    int peak_rating = -1;
    int peak_rank = INT_MAX;
    int rating_month = -1;
    int ranking_month = -1;
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int c[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> c[i][j];
        }

        vector<player> p(n);

        for (int j = 0; j < m; j++)
        {
            vector<pair<int, int>> vect;
            for (int i = 0; i < n; i++)
            {
                v[i] += c[i][j];
                if (v[i] > p[i].peak_rating)
                {
                    p[i].peak_rating = v[i];
                    p[i].rating_month = j;
                }
                vect.push_back({v[i], i});
            }

            sort(vect.begin(), vect.end());
            reverse(vect.begin(),vect.end());
            vector<int> rank(n);
            for (int i = 0; i < n; i++)
            {
                if (i == 0)
                {
                    rank[vect[0].second] = 1;
                    continue;
                }
                pair<int, int> curr = vect[i], prev = vect[i - 1];
                if (curr.first == prev.first)
                    rank[curr.second] = rank[prev.second];
                else
                    rank[curr.second] = i + 1;
            }

            for (int i = 0; i < n; i++)
            {
                if (rank[i] < p[i].peak_rank)
                {
                    p[i].peak_rank = rank[i];
                    p[i].ranking_month = j;
                }
            }
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=p[i].ranking_month!=p[i].rating_month;
        }

        cout<<ans<<'\n';
    }
    return 0;
}
