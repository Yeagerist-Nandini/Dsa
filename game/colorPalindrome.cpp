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


int main() {
	// your code goes here
	int t;
	cin>>t ;

	while(t--)
	{
	   int a,k;
	   cin>>a>>k;
	   string s;
	   cin>>s;
	   
	   map<char,int> mp;
	   
	   for(int i=0;i<s.size();i++)
	   {
	       mp[s[i]]++;
	   }
	   
	   int cnt=0,leftover=0;
	   
	   for(auto it=mp.begin();it!=mp.end();it++)
	   {
	       if(it->second%2==1)
	       {
	          leftover++;
	       }
	       cnt+=it->second /2;  //counting pairs
	   }
	   
	   leftover+=(2*(cnt%k));
	   if(leftover>=k)                   //pal m middle element nhi he
	   cout<<(cnt/k)*2 +1<<endl;         //agar daalna h to sbme middle ele daalna padega 
	   else                              //that's why leftovers k se bade ya equal hone chahye 
	   cout<<(cnt/k)*2<<endl; 
	}
	return 0;
}









