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
    int n;
    cin >> n;
    map<ll, pair<ll, ll>> mp;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        mp[x].first = i+1;
        mp[x].second = n - i;
    }
    ll V = 0,S = 0;
    ll m;
    cin >> m;
    while(m--){
        ll f;cin >> f;
        V += mp[f].first;
        S += mp[f].second;
    }
    cout << V << " " << S << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}