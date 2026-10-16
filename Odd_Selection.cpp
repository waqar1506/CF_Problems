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
    int n,x;
    cin >> n >> x;
    vi A(n);
    vi odEv(2,0);
    for(int i = 0;i < n;i++){
        cin >> A[i];
        odEv[A[i]%2]++;
    }
    bool f = 0;
    for(int i = 1;i <= odEv[1] && i <= x;i+=2){
        int h = odEv[0];
        int hn = x - i;
        if(hn <= odEv[0]){
            f = 1;
        }
    }
    if(f){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }

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