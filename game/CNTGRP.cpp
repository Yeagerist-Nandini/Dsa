#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<int> v;
#define mod 1000000007
ll n,m;


long long BinaryExponentiation(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


int main() {
	// your code goes here
	int t;
	cin>>t ;

	while(t--)
	{
	    v.clear();
	    cin>>n>>m;
	    
	    v=vector<int>(n+2);
	    v[0]++;
	    for(int i=0;i<n-1;i++)
	    {
	        int pos;
	        cin>>pos;
	        v[pos]++;
	    }
	    
	    //step 2,3 
	    bool flag=true;
	    ll ans=1;
	    for(int i=1;i<n;i++)
	    {
	        if(v[i-1]==0 && v[i]>0)
	        {
	            ans=false;
	            break;
	        }
	        if(v[i]>0)
	        ans=ans*BinaryExponentiation(v[i-1],v[i],mod);
	        
	        ans%=mod;
	    }
	    
	    if(!flag)
	    {
	        cout<<false<<endl;
	        continue;
	    }
	    
	    //step 4
	    ll nodePair=0;
	    for(int i=1;i<n-1;i++)
	    {
	        ll count=v[i];
	        nodePair+=(count*(count-1))/2;
	    }
	    
	    //step 5
	    if(m-(n-1)>0)
	    {
	        m-=(n-1);
	        if(m>nodePair)
	        ans=0;
	        else
	        {
	            ll ways=0,num=1,den=1;
	            for(ll i=nodePair-m+1;i<=nodePair;i++){
	                num*=i;
	                num%=mod;
	            }
	            
	            for(int i=1;i<=m;i++)
	            {
	                den*=i;
	                den%=mod;
	            }
	            ways=num*BinaryExponentiation(den,mod-2,mod);
	            ways%=mod;
	            ans=(ans*ways)%mod;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}

