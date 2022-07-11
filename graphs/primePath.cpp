#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int mini=INT_MAX;

map<int,vector<int>> v;

vector<int> isPrime()
{
    vector<bool> seive(10000,true);

    seive[0]=seive[1]=false;
	for(int i=2;i*i<=10000;i++)
	{
		if(seive[i]==false)
		continue;

		for(int j=i*i;j<=10000;j+=i)
		seive[j]=false;
	}

	vector<int> prime;
	for(int i=1000;i<=9999;i++)
	{
		if(seive[i])
		prime.push_back(i);
	}
	return prime;
}

bool isConnected(int a, int b)
{
    string x,y;
    x=to_string(a);
    y=to_string(b);
	return ( (x[0]!=y[0] && x[1]==y[1] && x[2]==y[2] && x[3]==y[3]) || (x[0]==y[0] && x[1]!=y[1] && x[2]==y[2] && x[3]==y[3]) || (x[0]==y[0] && x[1]==y[1] && x[2]!=y[2] && x[3]==y[3]) || (x[0]==y[0] && x[1]==y[1] && x[2]==y[2] && x[3]!=y[3]) );
}

void build_graph(vector<int> prime)
{
    for(int i=0;i<prime.size();i++)
	{
		for(int j=i+1;j<prime.size();j++)
		{
			if(isConnected(prime[i],prime[j]))
			{
				v[prime[i]].push_back(prime[j]);
				v[prime[j]].push_back(prime[i]);
			}
		}
	}
}

int bfs(int a,int b)
{
    map<int,int> dist;
    for(auto it=v.begin();it!=v.end();it++)
    {
        dist[it->first]=INT_MAX;
    }

	queue<int> q;
	q.push(a);
	dist[a]=0;
	while(!q.empty())
	{
        int node=q.front();
		q.pop();

		for(auto nbr:v[node])
		{
			if(dist[nbr]==INT_MAX)
			{
				q.push(nbr);
				dist[nbr]=dist[node]+1;
			}
		}
	}

	return dist[b];
}

int main()
{
	vector<int> prime=isPrime();
    build_graph(prime);

    int t;
	cin>>t;
    // t=1;
	while(t--)
	{
		int a,b;
		cin>>a>>b;
        
		if(a==b)
		cout<<0<<endl;
		else
		{
			int ans=bfs(a,b);
			if(ans==INT_MAX)
			cout<<"Impossible"<<endl;
			else
			cout<<ans<<endl;
		}
    }

    return 0;
}