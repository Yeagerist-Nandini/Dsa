#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Graphs
{
    int v;
    list<int> *l;

public:
    Graphs(int v)
    {
        this->v = v;
        l=new list<int>[v+1];
    }

    void addEdge(int a,int b)
    {
        l[a].push_back(b);
		l[b].push_back(a);
    }

    bool dfs_helper(int node,vector<int> &vis,int m,int mc,int &cnt,int cat[])
	{
		vis[node]=true;
		// cout<<node<<" ";

		if(cat[node]==1)
		mc--;
		else if(cat[node]==0)
		mc=m;
		
		if(l[node].size()==1 && mc>=0 && node!=1){
		cnt++;
		return true;
		}

		if(l[node].size()==1 && mc<0 && node!=1)
		return false;

		if(mc<0)
		return false;

        bool flag=false;
		for(auto nbr:l[node])
		{
			if(vis[nbr]==false)
			{
				bool f=dfs_helper(nbr,vis,m,mc,cnt,cat);;
				flag=flag || f;
			}
		}

		return flag;
	}
    
    int dfs(int m,int cat[])
    {
        vector<int> vis(v+1,false);
        int cnt=0;
		
		dfs_helper(1,vis,m,m,cnt,cat);
		return cnt;
    }
};

int main()
{
    int t;
	t=1;
	while(t--)
	{
		int n,m;
		cin>>n>>m;

		int cat[n+1]={0};
		for(int i=0;i<n;i++)
		cin>>cat[i+1];

        Graphs g(n);
		for(int i=0;i<n-1;i++)
		{
           int x,y;
		   cin>>x>>y;
		   g.addEdge(x,y);
		}

		int ans=g.dfs(m,cat);
		cout<<ans<<endl;
    }

//     7 1
// 1 0 1 1 0 0 0
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7

    return 0;
}