#include<bits/stdc++.h>
using namespace std;


#define max 500001
#define mod 1000000007


typedef long long ll;



vector<ll> seive()
{
    vector<ll> prime;
    bool isPrime[max];
    isPrime[0]=isPrime[1]=false;
    
    for(int i=2;i<=max;i++){
		isPrime[i] = true;
	}
    
    for(int i=2;i*i<=max;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i;j<=max;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
    
    for(int i=2;i<=max;i++)
    {
        if(isPrime[i])
        prime.push_back(i);
    }
    
    return prime;
}


ll divisors(int n,vector<ll> prime)
{
    ll result = 1;
	for(int i=0;prime[i]<=n;i++){
		int k = prime[i];
		ll count = 0;
		while((n/k)!=0){
			count = (count + (n/k))%mod;
			k = k*prime[i];
		}
		result = (result * ((count+1)%mod))%mod;
	}
	return result;
}

int main(){
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<ll> prime=seive();
        cout<<divisors(n,prime)<<endl;
    }
    return 0;
}