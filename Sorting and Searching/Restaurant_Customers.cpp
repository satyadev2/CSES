// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define vll vector<long long>
// #define pb push_back
// #define ss second
// #define ff first
// #define sum(vec) accumulate(vec.begin(), vec.end())
// #define win(vec) vec.begin(), vec.end()
// #define rwin() vec.rbegin(), vec.rend()
// // 2^k--->(n && (!(n & (n - 1))))  ---(n & (n-1))
// //-- -- -- -- -- --Sieve------------- //
// vector<int> sieveOfEratosthenes(int n)
// {
//     vector<bool> prime(n + 1, true);
//     vector<int> primes;
//     prime[0] = prime[1] = false;
//     for (int p = 2; p * p <= n; ++p)
//     {
//         if (prime[p])
//         {
//             for (int i = p * p; i <= n; i += p)
//             {
//                 prime[i] = false;
//             }
//         }
//     }
//     for (int p = 2; p <= n; ++p)
//     {
//         if (prime[p])
//         {
//             primes.push_back(p);
//         }
//     }
//     return primes;
// }
// //-------------------main-------------------//
// int main()
// {
//     ll n;
//     cin >> n;
//     int k = n;
//     vector<pair<ll, ll>> nums;
//     while (k--)
//     {
//         ll x, y;
//         cin >> x >> y;
//         nums.push_back({x, y});
//     }
//     ll count = 1;
//     ll maxi = 1;
//     sort(nums.begin(), nums.end());
//     ll start = nums[0].first;
//     ll end = nums[0].second;
//     for (int i = 1; i < n; i++)
//     {
//         cout << start << " " << end << endl;
//         if (nums[i].first >= end)
//         {
//             start = nums[i].first;
//             end = nums[i].second;
//             count = 1;
//         }
//         else
//         {
//             start = max(start, nums[i].first);
//             end = min(end, nums[i].second);
//             count++;
//         }
//         maxi = max(maxi, count);
//     }
//     cout << maxi << endl;

//     return 0;
// }

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
    ll t;
    cin >> t;
    vector<pair<ll, ll>> nums;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        nums.push_back({x, y});
    }
    vector<pair<ll, ll>> rest;
    for (auto i : nums)
    {
        rest.push_back({i.first, 1});
        rest.push_back({i.second, -1});
    }
    ll count = 0;
    ll maxi = 0;
    sort(rest.begin(), rest.end());
    for (auto i : rest)
    {
        if (i.second == -1)
        {
            count--;
        }
        else
        {
            count++;
        }
        maxi = max(maxi, count);
    }
    cout << maxi;

    return 0;
}