#include<bits/stdc++.h>
using namespace std;

const int N = 105;
 
vector<int> graph[N];
bool vis[N]={false};
int x[N], y[N];

void dfs(int i)
{
	vis[i]=true;

	for(auto it:graph[i])
	{
		if(!vis[it])
		dfs(it);
	}
}

int main()
{
	int n;
	cin>>n;

	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}

    int cnt=0;

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(x[i]==x[j] || y[i]==y[j])
			{
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		if(vis[i])
		continue;

		cnt++;
		dfs(i);
	}

	cout<<cnt-1;
	return 0;
}