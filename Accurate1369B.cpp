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
bool nonIncreasing(string s){
    for(int i = 0;i < s.size() - 1;i++){
        if(int(s[i]) > int(s[i+1])){
            return false;
        }
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t;
    if(nonIncreasing(s)){
        cout << s << endl;
        return;
    }else{
        string ans;
        // Leading Zeroes
        for(int i = 0;i < s.size();i++){
            if(s[i] == '1'){
                break;
            }
            ans.push_back('0');
        }
        ans.push_back('0');
        // Trailing Zeroes
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == '0'){
                break;
            }
            ans.push_back('1');
        }
        cout << ans << endl;
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