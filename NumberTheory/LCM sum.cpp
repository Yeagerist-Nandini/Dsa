#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
vector<long> res(1000001);
vector<long> phi(1000001);
 
int flag=0;
 
void eulerphi(int n)
{
    res.clear();
    phi.clear();
    
    for(int i=1; i<=n; i++)
    {
        phi[i]=i;
    }
    for(int i=2; i<=n; i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(int j=i*2; j<=n; j+=i)
            {
                phi[j]=(phi[j]*(i-1))/i;
            }
        }
    }
    
    for (long i = 1; i <= n; ++i) {
        for (long j = i; j <= n; j += i) {
            res[(int)j] += (i * phi[(int)i]);
        }
    }
}
 
 
void sumOfLCM(int n)
{
     if (flag == 0) {
        eulerphi(1000000);
        flag = 1;
    }
     
    
    long ans = res[(int)n] + 1;
    ans *= n;
    ans /= 2;
    
    cout<<ans<<endl;
}
 
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
 
        sumOfLCM(n);
    }
    return 0;
}