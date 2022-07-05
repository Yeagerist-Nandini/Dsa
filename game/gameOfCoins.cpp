#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}


#define mod 1000000007
const int maxi=1e8;





int main() {
    int n;
    cin>>n;
    
bool dp[n+1];
dp[0]=false;
dp[1]=true;
dp[2]=false;
dp[3]=true;
dp[4]=true;

for(int i=5;i<=n;i++)
{
    dp[i]=(dp[i-1] && dp[i-3] && dp[i-4]);
    dp[i]=!dp[i];
}

for(int i=0;i<=n;i++)
cout<<dp[i]<<" ";
	return 0;
}

//   0  1   2   3   4   5   6   7   8   9   10  11
//   L	W	L	W	W	W	W	L	W	L	W	W





