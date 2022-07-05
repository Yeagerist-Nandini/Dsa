#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxi=1e8;


vector<int> isPrime(vector<bool> seive)
{
    for(ll i=2;i*i<=maxi;i++)
    {
        if(seive[i]==false)
        continue;

        for(ll j=i*i;j<=maxi;j+=i)
        {
            seive[j]=false;
        }
    }
   
    vector<int> primes;
    
    for(int i=2;i<=maxi;i++)
    {
        if(seive[i])
        primes.push_back(i);
    }

    return primes;
}

int main()
{
    vector<bool> seive(maxi+1,true);
    seive[0]=seive[1]=false;
     
    isPrime(seive);

    return 0;
}








