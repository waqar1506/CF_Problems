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
    vi A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int cntres = 0;
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            int cnt = 0;
            for(int k = 0;k < i;k++){
                if(A[k] == 1){
                    cnt++;
                }
            }
            for(int k = i;k <= j;k++){
                if(A[k] == 0){
                    cnt++;
                }
            }
            for(int k = j+1;k < n;k++){
                if(A[k] == 1){
                    cnt++;
                }
            }
            cntres = max(cntres,cnt);
        }
    }
    cout << cntres << endl;
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