#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back
#define ss second
#define ff first
#define sum(vec) accumulate(vec.begin(), vec.end())
#define win(vec) vec.begin(), vec.end()
#define rwin() vec.rbegin(), vec.rend()
// 2^k--->(n && (!(n & (n - 1))))  ---(n & (n-1))
//-- -- -- -- -- --Sieve------------- //
vector<int> sieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    vector<int> primes;
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; ++p)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; ++p)
    {
        if (prime[p])
        {
            primes.push_back(p);
        }
    }
    return primes;
}
//-------------------main-------------------//
int main()
{
    ll applicants, apartments, offset;
    cin >> applicants >> apartments >> offset;
    vector<ll> app(applicants);
    vector<ll> apart(apartments);
    for (ll i = 0; i < applicants; i++)
    {
        cin >> app[i];
    }
    for (ll i = 0; i < apartments; i++)
    {
        cin >> apart[i];
    }
    sort(app.begin(), app.end());
    sort(apart.begin(), apart.end());
    ll i = 0;
    ll j = 0;
    ll count = 0;
    while (i < apartments && j < applicants)
    {
        // cout << apart[i] << " " << app[j] << endl;
        if (abs(apart[i] - app[j]) <= offset)
        {
            count++;
            i++;
            j++;
        }
        else if (apart[i] > app[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    cout << count;

    return 0;
}