#include <bits/stdc++.h>
using namespace std;

//bit manipulation

//left shift-> n<<i => n*(2^i);
//right shift->n>>i => n*(1/(2*i));

bool checkBit(int n, int i)
{
    if (n & (1 << i) == 0)
        return 0;
    else
        return 1;
}

int flipBit(int &n, int i)
{
    return n ^ (1 << i);
}

int unset(int &n, int i)
{
    n = n & ~(1 << i);
    return n;
}

int setb(int &n, int i)
{
    n = n | (1 << i);
    return n;
}

bool checkPowerOf2(int n)
{
    if (n & (n - 1) == 0)
        return true;
    else
        return false;
}

bool even(int n)
{
    if (n & 1 == 0)
        return true;
    return false;
}

int cntSetBits(int n)
{
    int cnt=0;
    for (int i = 0; (1<<i)<=n; i++)          //we dont have to check for 30 becoz 2^30 > 10e9
    {
        if (n & (i << i) != 0)      //checking if bit is set or not
        {
            cout << i << " ";
            cnt++;
        }
    }
    
    return cnt;
}

int main()
{
    int n = 5;

    cout << checkPowerOf2(n) << endl;
    cout << even(5) << endl;
    cout << setb(n, 1) << endl;
    cout << unset(n, 1) << endl;
    cout << checkBit(n, 0) << endl;
    cout << flipBit(n, 0) << endl;
    return 0;
}