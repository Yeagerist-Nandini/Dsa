#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mod 1000000007

void multiply(int a[2][2], int M2[2][2])
{
    ll a11 = a[0][0] * M2[0][0] + a[0][1] * M2[1][0];
    ll a12 = a[0][0] * M2[0][1] + a[0][1] * M2[1][1];
    ll a21 = a[1][0] * M2[0][0] + a[1][1] * M2[1][0];
    ll a22 = a[1][0] * M2[0][1] + a[1][1] * M2[1][1];

    a[0][0] = a11;
    a[0][1] = a12;
    a[1][0] = a21;
    a[1][1] = a22;
}

void power(int a[2][2], ll n)
{
    if (n == 0 || n == 1)
        return;

    power(a, n / 2);
    multiply(a, a);

    if (n % 2 == 1)
    {
        int m[2][2] = {{1, 1}, {1, 0}};
        multiply(a, m);
    }
}

ll fib(ll n)
{
    int a[2][2] = {{1, 1}, {1, 0}};

    if (n == 0)
        return 0;

    if (n == 1 || n == 2)
        return 1;

    power(a, n - 1);

    return a[0][0] % mod;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        ll sum = 0;
        for (ll i = n; i <= m; i++)
        {
            sum += fib(i);
            sum = sum % mod;
        }

        cout << sum << endl;
    }
    return 0;
}