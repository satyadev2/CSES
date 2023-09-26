#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<long long>
#define pb push_back

int main()
{
    ll t;
    cin >> t;
    vector<ll> nums(t);
    for (ll i = 0; i < t; i++)
    {
        cin >> nums[i];
    }
    ll i = 0, j = 0;
    map<ll, ll> satyaa;
    ll count = 0;
    ll maxi = INT_MIN;
    while (j < nums.size())
    {
        satyaa[nums[j]]++;
        while (satyaa[nums[j]] != 1)
        {
            satyaa[nums[i]]--;
            if (satyaa[nums[i]] == 0)
            {
                satyaa.erase(nums[i]);
            }
            i++;
        }
        j++;
        maxi = max(maxi, j - i);
    }
    cout << maxi << endl;

    return 0;
}
