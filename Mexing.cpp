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

// MEX - O(n)
// int mex(vi const& A){

//     static bool used[250] = {false};
//     for(int x : A){
//         if(x <= INF){
//             used[x] = true;
//         }
//     }
//     int res = 0;
//     while(used[res]){
//         ++res;
//     }

//     for(int x : A){
//         if(x <= INF){
//             used[x] = false;
//         }
//     }
//     return res;
// }
// 


// Long Approach With Test Case Failure #12 (greater element doesn't matter)


// void solve(){
//     int n,x;
//     cin >> n >> x;
//     vector<int> prMex(n);
//     for(int i = 0;i < n;i++){
//         cin >> prMex[i];
//     }

//     int ans = mex(prMex);
//     int opt = 0;
//     if(ans == x){
//         cout << opt << endl;
//     }else{
//         // 1 != 3
//         while(ans != x){
//             if(ans < x){
//                 prMex.push_back(ans);
//                 opt++;
//             }else if(ans > x){
//                 prMex.erase(prMex.begin());
//                 opt++;
//             }
//             ans = mex(prMex);
//         }
//         cout << opt << endl;
//     }
// }

// Optimal ->
void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> B(105,0);
    while(n--){
        int e;
        cin >> e;
        B[e] = 1;
    }
    int ans = B[x];
    for(int i = 0;i < x;i++){
        ans+=!B[i];
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
    solve();
    return 0;
}