#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> tickets(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> tickets[i];
    }

    multiset<int> availableTickets(tickets.begin(), tickets.end());

    for (int i = 0; i < m; ++i)
    {
        int maxPrice;
        cin >> maxPrice;

        auto it = availableTickets.upper_bound(maxPrice); // Find the first ticket with a price that exceeds maxPrice

        if (it != availableTickets.begin())
        {
            --it; // Move to the previous ticket (nearest possible price that doesn't exceed maxPrice)
            cout << *it << "\n";
            availableTickets.erase(it); // Remove the sold ticket
        }
        else
        {
            cout << "-1\n"; // No ticket available within the budget
        }
    }

    return 0;
}