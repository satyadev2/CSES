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
    ll children, max_allowed;
    cin >> children >> max_allowed;
    vector<ll> child(children);
    for (ll i = 0; i < children; i++)
    {
        cin >> child[i];
    }
    sort(child.begin(), child.end());
    ll i = 0;
    ll j = children - 1;
    ll count = 0;
    while (i <= j)
    {
        if (child[i] + child[j] <= max_allowed)
        {
            count++;
            i++;
            j--;
        }
        else
        {
            count++;
            j--;
        }
    }
    cout << count;
    return 0;
}