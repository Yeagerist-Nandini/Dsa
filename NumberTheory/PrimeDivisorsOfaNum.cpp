#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int maxi=1e8;
 
 
void isPrime(vector<bool> seive,int n)
{
    
    for(ll i=2;i*i<=n;i++)
    {
        if(seive[i]==false)
        continue;
 
        for(ll j=i*i;j<=n;j+=i)
        {
            seive[j]=false;
        }
    }
    
    for(int i=2;i<=n;i++)
    {
        if(seive[i]==true && n%i==0)
       {
           cout<<i<<" ";
       }
    }
    cout<<endl;
}
 
int main()
{
    int t;
    cin>>t;
    int c=1;
    while(c!=t+1)
    {
        int n;
        cin>>n;
        
        vector<bool> seive(n+1,true);
    seive[0]=seive[1]=false;
    
    cout<<"Case "<<c<<": ";
    isPrime(seive,n);
    c++;
    }
    
    return 0;
}