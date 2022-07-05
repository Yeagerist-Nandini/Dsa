#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxi=1e6;

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int gcd(int a,int b)
{
    if(b>a)
        return gcd(b,a);
    
    if(b==0)
        return a;
    return gcd(b,a%b);
}

void LCM(int n,int arr[])
{
    ll partial_sum=arr[0];
    for(int i=1;i<n;i++)
    {
        partial_sum=(arr[i]*partial_sum)/gcd(arr[i],partial_sum);
    }

    cout<<partial_sum<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
       int n;
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++)
       cin>>arr[i];
       
       if(n>1)
       LCM(n,arr);
       else if(n==1)
       {
           cout<<arr[0]*arr[0]<<endl;
       }
    }
    
    return 0;
}








