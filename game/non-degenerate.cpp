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
    
    if(n<3)
    {
        cout<<"NO";
        return 0;
    }
    
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    sort(arr,arr+n);
    
    for(int i=0;i<n-2;i++)
    {
        if(arr[i]+arr[i+1]>arr[i+2])
        {
            cout<<"YES";
            return 0;
        }
    }
    
    cout<<"NO";
	return 0;
}


//degenerate triangles
// (a+b<=c)

//non degenerate triangles
//positive area
//a+b<c
//b+c<a
//a+c<b






