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

const int MAX =505;
int a[MAX][MAX], res[MAX];
int n, m, q;
void calc(int i)
{
	res[i] = 0;
	int cnt = 0;
	for (int j = 0; j <= m; j++)
		if (a[i][j])
			cnt++;
		else
		{
			res[i] = max(res[i], cnt);
			cnt = 0;
		}
}
int main()
{
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
		calc(i);
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		a[x - 1][y - 1] ^= 1;
		calc(x - 1);
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans = max(ans, res[i]);
		cout << ans << endl;
	}
	return 0;
}

// int main() {
// ll n,m;
// cin>>n;

// ll arr[n];
// for(int i=1;i<=n;i++)
// cin>>arr[i];

// ll dp[n+1]={0};
// dp[0]=0;

// for(int i=1;i<=n;i++)
// {
//     for(int j=i;j<n;j++)
//     {
//         if(arr[j]==arr[(((j-1)/4)*4)+3])
//         dp[i]++;
//         else if(arr[j]==arr[(((j-2)/4)*4)+4])
//         dp[i]++;
//         else break;
//     }
    
//     dp[i]=max(dp[i],dp[i-1]);
// }

// cout<<dp[n];
// return 0;
// }




