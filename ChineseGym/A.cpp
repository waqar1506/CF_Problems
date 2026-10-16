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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    // Provincial-level historic cities: 
    // an shun (安顺), zhi jin (织金), da fang (大方), shi qian (石阡), li ping (黎平), fu quan (福泉), an long (安龙), pu ding (普定), si nan (思南), and zhen feng (贞丰).
    set<string> setCities = {
        "an shun", 
        "zhi jin", 
        "da fang", 
        "shi qian", 
        "li ping", 
        "fu quan", 
        "an long", 
        "pu ding",
        "si nan",
        "zhen feng"
    };
    string s;
    getline(cin,s);
    if(setCities.count(s)){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
    return 0;
}