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

bool allElement(vector<ll> A){
    for(int i = 1;i < A.size();i++){
        if(A[i] != A[i-1]){
            return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vll teamMember(n);
    for (int i = 0; i < n; i++)
    {
        cin >> teamMember[i];
    }

    sort(teamMember.begin(), teamMember.end());
    // Basic Variable Sliding Window Pattern

    int score = 0;
    int j = 0;
    for(int i = 0;i < n;i++){
        while(j < n && teamMember[j] - teamMember[i] <= 5){
            ++j;
            score = max(score,j-i);
        }
    }
    cout << score << endl;
    return 0;
}
