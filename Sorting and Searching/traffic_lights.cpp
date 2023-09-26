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
    ll x, n;
    cin >> x >> n;
    set<ll> indices;
    multiset<ll> difference;
    indices.insert(0);
    indices.insert(x);
    difference.insert(x);
    for (ll i = 0; i < n; i++)
    {
        ll data;
        cin >> data;
        indices.insert(data);
        auto it = indices.find(data); // taken out positions
        // now delete this number from differennce
        // set me search kara aage picche kon hai
        ll aage = *prev(it);
        ll picche = *next(it);
        // difference le liya nye walo se
        ll l1 = abs(aage - data);
        ll l2 = abs(picche - data);
        // removed [n-1] value(initially) and added 2 different number
        difference.erase(difference.find(picche - aage));
        difference.insert(l1);
        difference.insert(l2);
        cout << *difference.rbegin() << " ";
    }

    return 0;
}

// sexy problem