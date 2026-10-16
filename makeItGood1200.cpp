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

void solve(){
    int n;
    cin >> n;
    vi A(n);
    for(int i = 0;i < n;i++){
        cin >> A[i];
    }
    int p = n - 1;
    while(p > 0 && A[p-1] >= A[p]){
        --p;
    }
    while(p > 0 && A[p-1] <= A[p]){
        --p;
    }
    cout << p << endl;
}

void solve2(){
    int n;
    cin >> n;
    map<string,int> mp;
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        mp[s]++;
        if(mp[s] == 1){
            cout << "No\n";
        }else if(mp[s] > 1){
            cout << "Yes\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
    solve2();

    return 0;
}