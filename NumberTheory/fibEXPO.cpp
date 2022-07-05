#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

#define long long long
const long M = 1000000007; // modulo
map<long, long> F;
// F[0]=F[1]=1;

long f(long n) {
	if (F.count(n)) return F[n];
	long k=n/2;
	if (n%2==0) { // n=2*k
		return F[n] = (f(k)*f(k) + f(k-1)*f(k-1)) % M;
	} else { // n=2*k+1
		return F[n] = (f(k)*f(k+1) + f(k-1)*f(k)) % M;
	}
}


int main(){
    int t;
    cin>>t;
    F[0]=F[1]=1;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        
        ll sum=0;
        for(ll i=n;i<=m;i++)
        {
            sum+=(i==0 ? 0 : f(i-1));
            sum=sum%M;
        }
        
        cout<<sum<<endl;
    }
    return 0;
}