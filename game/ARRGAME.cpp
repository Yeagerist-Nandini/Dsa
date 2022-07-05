#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> v;
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
	    v.clear();
        cin>>n;

        int fmax=0,smax=0,zero=0;
        v=vector<ll> (n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            if(v[i]==1)
            {
                if(zero!=0)
                {
                    if(zero>fmax)
                    {
                        smax=fmax;
                        fmax=zero;
                    }
                    else if(zero>smax)
                    smax=zero;
                    zero=0;
                }
            }
            else
            zero++;
        }
        if(fmax==0 && smax==0)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(fmax==1 && smax==0)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        
        if(fmax%2!=0 && smax<(fmax+1)/2)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
	}
	return 0;
}









