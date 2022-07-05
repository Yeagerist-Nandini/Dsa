#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}


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


ll decimalToBinary(ll N)
{
    ll B_Number = 0;
    ll cnt = 0;
    while (N != 0) {
        ll rem = N % 2;
        ll c = BinaryExponentiation(10,cnt,mod);
        B_Number += rem * c;
        N /= 2;
        cnt++;
    }

    return B_Number;
}

bool checkBit(ll n,int i)
{
    if(n&(1<<i)==0)
    return 0;
    else 
    return 1;
}

int main() {
	// your code goes here
	int t;
	cin>>t ;

	while(t--)
	{
	  ll n,k;
	  cin>>n>>k;
	  
	  ll ans=0,p=1;
	  for(int i=0;i<31;i++)
	  {
	      if(k&(1<<i))
	      ans=(ans+p)%mod;
	      
	      p*=n;
	      p%=mod;
	  }
	  
	  cout<<ans<<endl;
	}
	return 0;
}








