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
// Initial Logic of mine is correct but partially

int primeCheck(int n){
    for(int i = 2;i < min(n,50000);i++){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
void solve() {
    int n;
    cin >> n;

    bool win = (n == 1);
    if(n > 2 && n % 2 == 0){
        if((n&(n-1)) == 0){
            win = 1;
        }else if(n % 4 != 0 && primeCheck(n/2)){
            win = 1;
        }
    }
    if(win){
        cout <<"FastestFinger\n";
    }else{
        cout<<"Ashishgup\n";
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