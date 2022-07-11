#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

class Graphs
{
    int v;
    // unordered_map<int, vector<pair<int, int>>> l;
    list<pair<int,int>> *l;

public:
    Graphs(int v)
    {
        this->v = v;
        l=new list<pair<int,int>>[v+1];
    }

    void addEdge(int a, int b, int wt)
    {
        l[a].push_back({b, wt});
        l[b].push_back({a, wt});
    }

    void dijkstra(int src,int dest)
    {
		ll u=1e15;

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        
        map<int,ll> dis;
		map<int,int> parent;
        for(int i=0;i<=v;i++)
        dis[i]=u;
     
        dis[src] = 0;
		parent[src]=-1;
        pq.push({0, src});
        while (!pq.empty())
        {
            ll dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto nbr:l[node])
            {
                auto nxt = nbr.first;
                auto wt = nbr.second;
                if (dis[nxt] > dis[node] + wt)
                {
					parent[nxt]=node;
                    dis[nxt] = dis[node] + wt;
                    pq.push({dis[nxt], nxt});
                }
            }
        }

        if(dis[v]==u)
		cout<<-1<<endl;
		else
		{
			vector<int> ans;
			int t=v;
			while(t!=-1)
			{
				ans.push_back(t);
				t=parent[t];
			}

			for(int i=ans.size()-1;i>=0;i--)
			cout<<ans[i]<<" ";
		}
    }
};

int main()
{
    int v,m;
    cin>>v>>m;

    Graphs g(v);
    int src=1,dest=v;
    for(int i=0;i<m;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        g.addEdge(x,y,wt);
    }

    g.dijkstra(src,dest);
    return 0;
}