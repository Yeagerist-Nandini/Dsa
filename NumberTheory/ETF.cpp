#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
vector<ll> eulerPhi(ll n)
{
    vector<ll> phi(n+1);
    
    for(int i=1;i<=n;i++)
        phi[i]=i;
    
    for(int i=2;i<=n;i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            
            for(int j=2*i;j<=n;j+=i)
            {
                phi[j]=(phi[j]*(i-1))/i;
            }
        }
    }
    
    return phi;
}
    
 
int main(){
	vector<ll> phi;
	phi=eulerPhi(1000001);
	
    int t;
    cin>>t;
    
    while(t--)
    {
        ll n;
        cin>>n;
        
        cout<<phi[n]<<endl;
    }
    return 0;
} 