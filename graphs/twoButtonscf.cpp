#include<bits/stdc++.h>

using namespace std;

const int maxn=2e4 +5;
int n,k,m;

int d[maxn]={0};

int solve()
{
	if(n>=m)
	return n-m;

    queue<int> q;
	q.push(n);
	d[n]=1;

	while(!q.empty())
	{
		int t=q.front();
		q.pop();

		if(t==m)
		return d[t]-1;

		int a=2*t;
		if(a<maxn && !d[a])
		{
			q.push(a);
			d[a]=d[t]+1;
		}
		a=t-1;
		if(a>0 && !d[a])
		{
			q.push(a);
			d[a]=d[t]+1;
		}
	}

	return 0;
}

int main() {
	// Your code goes here;
    cin>>n>>m;
	int ans=solve();
	cout<<ans<<endl;
	return 0;
}

