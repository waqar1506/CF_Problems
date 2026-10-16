#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    // e[i] = time when i becomes 0
    vector<ll> e(n + 1);

    // {death_time, index}
    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    int positive = 0;

    // Initial values
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;

        e[i] = x;

        if (x > 0) {
            positive++;
            pq.push(make_pair(e[i], i));
        }
    }

    for (int t = 1; t <= q; t++) {

        int x;
        ll v;

        cin >> x >> v;

        // Elements whose death time is t
        // become zero after this operation's decrement.
        while (!pq.empty() && pq.top().first <= t) {

            ll deathTime = pq.top().first;
            int idx = pq.top().second;

            pq.pop();

            // This is the current entry, not an old entry.
            if (e[idx] == deathTime) {
                positive--;
            }
        }

        // x = 0 means no update
        if (x != 0) {

            // Current value at index x:
            // e[x] - t
            //
            // We set:
            // max(current value, v)
            //
            // Therefore new death time:
            // t + max(e[x] - t, v)
            // = max(e[x], t + v)

            ll newDeath = max(e[x], t + v);

            // Check whether x was zero before update
            bool wasZero = (e[x] <= t);

            // Check whether it becomes positive
            bool becomesPositive = (newDeath > t);

            e[x] = newDeath;

            if (wasZero && becomesPositive) {
                positive++;
            }

            // Add the new version to heap
            if (newDeath > t) {
                pq.push(make_pair(newDeath, x));
            }
        }

        cout << positive << '\n';
    }

    // Final values
    for (int i = 1; i <= n; i++) {

        if (e[i] <= q) {
            cout << 0 << " ";
        }
        else {
            cout << e[i] - q << " ";
        }
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}