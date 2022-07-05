#include<bits/stdc++.h>
using namespace std;

typedef long long ll;



vector<int> prime(int n)
{
    vector<int> primes;
    bool sieve[1000001];
    sieve[0]=sieve[1]=false;
    for(int i=2;i<=n;i++)
        sieve[i]=true;
    
    for(int i=2;i*i<=n;i++)
    {
        if(sieve[i]==false)
            continue;
        
        for(int j=i*i;j<=n;j+=i)
        {
            sieve[j]=false;
        }
    }
    
    primes.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(sieve[i])
            primes.push_back(i);
    }
    
    return primes;
}


void printPrimes(ll l,ll r,vector<int> primes)
{
    bool isPrime[r-l+1];
    
    for(int i=0;i<=r-l;i++)
        isPrime[i]=true;
    
    for(int i=0;primes[i]*primes[i]<=r;i++)
    {
        int currprime=primes[i];
        ll base=(l/(currprime))*currprime;
        
        if(base<1)
            base+=currprime;
        
        for(ll j = base;j<=r ;j+= currprime){
			isPrime[j-l] = false;
		}
        
        if(base==currprime)
            isPrime[base-l]=true;
    }
    
    for(int i=0;i<=r-l;i++){
		if(isPrime[i] == true && i+l!=1){
			cout << i + l << " ";
		}
	}
 
}

int main(){
    vector<int> primes=prime(1000001);
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;
        
        printPrimes(l,r,primes);
        cout<<endl;
    }
    return 0;
}