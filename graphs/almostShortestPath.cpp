#include <bits/stdc++.h>
using namespace std;

class Graphs
{
    int v;
    int **l;

public:
    Graphs(int v)
    {
        this->v = v;
        l=new int*[v+1];
        for(int i=0;i<=v;i++)
        l[i]=new int[v+1];

        for(int i=0;i<=v;i++)
        {
            for(int j=0;j<=v;j++)
            l[i][j]=INT_MAX;
        }
    }

    void addEdge(int a, int b, int wt)
    {
        l[a][b]=wt;
    }

    int dijkstra(int src,int dest)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        map<int,int> dis;
        for(int i=0;i<=v;i++)
        dis[i]=INT_MAX;
     
        dis[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (int i=0;i<=v;i++)
            {
                if(l[node][i]==INT_MAX)
                continue;

                auto wt = l[node][i];
                auto nxt = i;
                if (dis[nxt] > dis[node] + wt)
                {
                    dis[nxt] = dis[node] + wt;
                    pq.push({dis[nxt], nxt});
                }
            }
        }

        int path =(dis[dest]==INT_MAX)?-1:dis[dest];
        return path;
    }


    bool dfs(int src,int res,int dest)
    {
        if(src==dest && res==0)
        {
            return true;
        }

        if(src==dest || res<0)
        return false;

        bool flag=false;
        for(int i=0;i<=v;i++)
        {
            if(l[src][i]==INT_MAX)
            continue;

            if(dfs(i,res-l[src][i],dest)==true)
            {
                 l[src][i]=INT_MAX;
                 flag=true;
            }
        }

        return flag;
    }
};

int main()
{
    int v,m;
	while(cin>>v>>m)
	{
		if(v==0 && m==0)
		return 0;
    Graphs g(v);
    int src,dest;
    cin>>src>>dest;
    for(int i=0;i<m;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        g.addEdge(x,y,wt);
    }

    int path=g.dijkstra(src,dest);
    if(path==-1)
    {
        cout<<-1<<endl;
        continue;
    }

    g.dfs(src,path,dest);
    path=g.dijkstra(src,dest);
    
    cout<<path<<endl;
    }

    return 0;
}