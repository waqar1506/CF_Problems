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
    int m;
    cin >> m;
    while (m--)
    {
        string s;
        cin >> s;
        if (s.size() != A.size())
        {
            cout << "No\n";
        }
        else
        {
            map<char, int> mp1;
            map<int, char> mp2;

            // Build the character to integer mapping
            for (int i = 0; i < n; i++)
            {
                mp1[s[i]] = A[i];
            }
            // Build the integer to character mapping
            for (int i = 0; i < n; i++)
            {
                mp2[A[i]] = s[i];
            }

            // Assume the mapping is valid initially
            bool ans = true;

            // Check whether the mapping is consistent
            for(int i = 0;i < s.size();i++){

                // If neither the character nor the integer has appeared
                // in its respective map, create a new mapping
                if(mp1.count(s[i]) == false && mp2.count(A[i]) == false){
                    mp1[s[i]] = A[i];
                    mp2[A[i]] = s[i];
                // If the character maps to different integer OR the integer
                // maps to a different character, the mapping is invalid
                }else if((mp1.count(s[i]) == true && mp1[s[i]] != A[i]) || (mp2.count(A[i]) == true && mp2[A[i]] != s[i])){
                    ans = false;
                    break;
                }
            }
            if(ans){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }

        }
    }
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