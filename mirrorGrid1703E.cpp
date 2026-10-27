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
    int a[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    }
    int ans = 0;
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int nowi = i, nowj = j;
            int oldnowj = nowj;
            int sum = a[nowi][nowj];
            nowj = n - nowi - 1;
            nowi = oldnowj;
            sum += a[nowi][nowj];
            oldnowj = nowj;
            nowj = n - nowi - 1;
            nowi = oldnowj;
            sum += a[nowi][nowj];
            oldnowj = nowj;
            nowj = n - nowi - 1;
            nowi = oldnowj;
            sum += a[nowi][nowj];
            ans += min(sum, 4 - sum);
        }
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