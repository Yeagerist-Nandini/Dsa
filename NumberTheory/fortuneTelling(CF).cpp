#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> v;
#define mod 1000000007


int main() {
	// your code goes here
	int t;
	cin>>t ;
     
    int sum=0,ans=0;
    int arr[t];
    for(int i=0;i<t;i++)
    {
        cin>>arr[i];
    }
    
    int odd=0,even=0,smallestOdd=INT_MAX;
    
    for(int i=0;i<t;i++)
    {
        if(arr[i]%2==0)
        {
            even+=arr[i];
        }
        else{
            odd+=arr[i];
            smallestOdd=min(smallestOdd,arr[i]);
        }
    }
    
    if(odd==0)
    cout<<0;
    else if(odd%2==0)
    cout<<odd+even-smallestOdd;
    else if(odd%2==1)
    cout<<even+odd;
    
	return 0;
}



//odd+odd=odd or even
// even+even=even
// odd+even=odd
//if(oddsum=>even)->oddsum+evensum(even+even)-smallestOdd(odd)->odd
// if(oddsum=>odd)->oddsum+evensum(odd+even)->odd




 