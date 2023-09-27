#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n, target;
    cin >> n >> target;

    map<ll, ll> satyaa;
    for (ll i = 0; i < n; i++)
    {
        ll data;
        cin >> data;
        if (satyaa[target - data] != 0)
        {
            cout << satyaa[target - data] << " " << i + 1;
            return 0;
        }
        else
        {
            satyaa[data] = i + 1;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}