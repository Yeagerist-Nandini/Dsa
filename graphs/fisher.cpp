#include <algorithm>
#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;
int tim[51][51];
int toll[51][51],grid[51][1001];

void init(int n,int t)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=t;j++)
		{
			if(i!=0)
			grid[i][j]=INT_MAX;
            else
			grid[i][j]=0;
		}
	}
}

void findPath(int n, int t){
	init(n, t);
	int finalNode = n-1;
	queue<int> q;
	q.push(0);
	q.push(0);
	while(!q.empty()){
		int start = q.front();
		q.pop();
		int timer = q.front();
		q.pop();
		for(int end = 1;end < n;end++){
			if(start == end)
				continue;
			int newTime = timer + tim[start][end];
			if(newTime <= t){
				int newToll = grid[start][timer] + toll[start][end];
				if(grid[end][newTime] > newToll){
					grid[end][newTime] = newToll;
					if(end != finalNode){
						q.push(end);
						q.push(newTime);
					}
				}
			}
		}
	}
	int minTime = 0, minToll = grid[finalNode][0];
	for(int i=1;i<=t;i++){
		if(minToll > grid[finalNode][i]){
			minTime = i;
			minToll = grid[finalNode][i];
		}
	}
	printf("%d %d\n", minToll, minTime);
}


int main() {
	int n,t;

	while(cin>>n>>t)
	{
	if(n==0 && t==0)
	return 0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int x,y;
			cin>>x;
			tim[i][j]=x;
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int x;
			cin>>x;
			toll[i][j]=x;
		}
	}

    findPath(n,t);
	}
	return 0;
}