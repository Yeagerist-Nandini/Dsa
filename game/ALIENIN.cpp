#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> v;
#define mod 1e9+7
ll n,d;

bool work(long double mid)
{
    long double time=0.0;
    for(int i=0;i<n;i++)
    {
        if(time<v[i])
        time=v[i]+mid;
        else if(time <=v[i]+d)
        time+=mid;
        else
        return false;
    }
    
    return true;
}

int main() {
	// your code goes here
	int t;
	cin>>t ;

	while(t--)
	{
	    v.clear();
	    long double high=1e10,low=0.0,mid;

	    cin>>n>>d;
	    
	    v= vector<int>(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>v[i];
	    }
	    
	    sort(v.begin(),v.end());
	    
	    while((high-low)>0.000001)
	    {
	        mid=(low+high)/2;
	        
	        if(work(mid))
	        low=mid;
	        else
	        high=mid;
	    }
	    
	    cout<<fixed<<setprecision(6)<<low<<endl;
	}
	return 0;
}
