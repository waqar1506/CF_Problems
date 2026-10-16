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

void solve() {
    int n;
    cin >> n;
    vi weight(n);
    map<int,int> mp;
    for(int i = 0;i < n;i++){
        cin >> weight[i];
        mp[weight[i]]++;
    }
    int ans = 0;
    for(int i = 2;i <= 2*n;i++){
        int pr = 0;
        for(int j = 1;j < (i+1)/2;j++){
            int k = i - j;
            pr += min(mp[j],mp  [k]);
        }
        if(i % 2 == 0){
            pr += mp[i/2]/2;
        }
        ans = max(ans,pr);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}