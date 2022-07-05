#include<bits/stdc++.h>
using namespace std;

//bit manipulation 

//left shift-> n<<i => n*(2^i);
//right shift->n>>i => n*(1/(2*i));

bool checkBit(int n,int i)
{
    if(n&(1<<i)==0)
    return 0;
    else 
    return 1;
}

int flipBit(int &n,int i)
{
    return n^(1<<i);
}

int unset(int &n,int i)
{
    n=n& ~(1<<i);
    return n;
}

int setb(int &n,int i)
{
    n=n|(1<<i);
    return n;
}

bool checkPowerOf2(int n)
{
    if(n&(n-1)==0)
    return true;
    else
    return false;
}

bool even(int n)
{
    if(n&1==0)
    return true;
    return false;
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int last=0;
       for(int i=0;i<30;i++)
       {
           if(n&(1<<i))
           last=i;
       }
       
       cout<<(1<<last)-1<<endl;
   }
    return 0;
}