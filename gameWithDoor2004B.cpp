#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vll = vector<ll>;

const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9 + 7;

void solve()
{
    int l, r, L, R;
    // Input the end point of the first and second intervals
    cin >> l >> r;
    cin >> L >> R;

    // Calculate the number of common integers points between the intervals
    int interS = min(r,R) - max(l,L) + 1;

    // Initialize the answer as the number of common points - 1
    int ans = interS - 1;

    // 
    if(interS <= 0){
        // If the points are not overlap, atleast one operation needed
        ans = 1;
    }else{
        // Add one if the left end points are different
        ans += (l != L);
        // Add one if the right end points are different
        ans += (r != R);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}