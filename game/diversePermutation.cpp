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
int n,k;
cin>>n>>k;

bool used[n]={false};
int l=1,r=n;
for(int i=0;i<k;i++)
{
   if((i&1)==0)
   {
       used[l-1]=true;
       cout<<l<<" ";
       l++;
   }
   else if((i&1)==1){
       used[r-1]=true;
       cout<<r<<" ";
       r--;
   }
}

if ((k & 1) == 1) {
      for (int i = 0; i < n; ++i) {
        if (!used[i]) {
          cout<<i+1<<" ";
        }
      }
    } else {
      for (int i = n-1 ; i >= 0; --i) {
        if (!used[i]) {
          cout<<i+1<<" ";
        }
      }      
    }


return 0;
}





