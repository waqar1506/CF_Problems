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

int compareVersion(string version1, string version2) {
    // Two Pointer Approach
    int i = 0;
    int j = 0;

    // Comparing in outer while
    while(i < version1.size() || j < version2.size()){
        int nv1 = 0;
        int nv2 = 0;
        // Extracting
        while(i < version1.size() && version1[i] != '.'){
            nv1 = nv1 * 10 + (version1[i] - '0');
            i++;
        }
        while(j < version2.size() && version2[j] != '.'){
            nv2 = nv2 * 10 + (version2[j] - '0');
            j++;
        }
        // Comparing
        if(nv1 < nv2){
            return -1;
        }
        if(nv1 > nv2){
            return 1;
        }
        // Skipping '.'
        if(i < version1.size()){
            i++;
        }
        if(j < version2.size()){
            j++;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cout << compareVersion("1.01","1.001");
    return 0;
}