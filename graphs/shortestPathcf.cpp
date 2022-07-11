#include<bits/stdc++.h>

using namespace std;
int n,k,m;
vector<vector<int>> g;
map<pair<int,int>,vector<int>> bad;

vector< vector< pair<int, int> > > parent;
pair<int, int> dest_cur;
 
bool isBad(const pair<int, int>& p, int next) {
	auto it = bad.find(p);
	if (it != bad.end()) {
		return find(it->second.begin(),it->second.end(),next) != it->second.end();
	}
	return false;
}


void bfs()
{
	vector< vector<bool> > vis(g.size(), vector<bool>(g.size(), false));
	vector< vector<int> > dist(g.size(), vector<int>(g.size(), 0));

	parent.clear();
	parent.resize(g.size(), vector< pair<int, int> >(g.size(), make_pair(-1, -1)));
 
	
	queue<pair<int,int>> q;
	q.push({0,1});
	vis[0][1]=true;
	dist[0][1]=0;
    dest_cur=make_pair(-1,-1);

	while(!q.empty())
	{
        auto temp=q.front();
		q.pop();
        vis[temp.first][temp.second]=true;

		if(temp.second==g.size()-1)
		{
			cout<<dist[temp.first][temp.second]<<endl;
			dest_cur=temp;
			break;
		}

		for(int i = 0; i < g[temp.second].size(); ++i)
		{
			int u=temp.second,v=g[temp.second][i];
			if(!isBad(temp,v) && !vis[u][v])
			{
				vis[u][v]=true;
				q.push({u,v});
				dist[u][v]=dist[temp.first][u]+1;
				parent[u][v]=temp;
			}
		}
	}

    if(dest_cur.first==-1 && dest_cur.second==-1)
	{
		cout<<-1<<endl;
		return;
	}	


   vector<int> path ;
   for(auto cur=dest_cur;cur!=make_pair(0,1);cur=parent[cur.first][cur.second])
   path.push_back(cur.second);
   path.push_back(1);
   reverse(path.begin(),path.end());

   for(int i=0;i<path.size();i++)
   cout<<path[i]<<" ";    
}

int main() {
	// Your code goes here;
    cin>>n>>m>>k;
	g.resize(n + 1);
	// g=new vector<int> [n+1];

	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int i=0;i<k;i++)
	{
		int u,v,p;
		cin>>u>>v>>p;
		bad[make_pair(u,v)].push_back(p);
	}

    bfs();
	return 0;
}

