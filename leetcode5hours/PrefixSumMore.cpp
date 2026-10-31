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

// Prefix Sum Template
vector<int> prefixSum(vector<int> &A){
    vector<int> pre(A.size()+1);
    pre[0] = 0;
    for(int i = 0;i < A.size();i++){
        pre[i+1] = pre[i] + A[i];
    }
    return pre;
}
// Subarray Sum Equals K
// Brute
int subarraySum(vi &a, int k){
    int cnt = 0;
    for(int i = 0;i < a.size();i++){
        int crntSum = 0;
        for(int j = i;j < a.size();j++){
            crntSum += a[j];
            if(crntSum == k){
                cnt++;
            }
        }
    }
    return cnt;
}

// Optimized 
int subarraySumOptim(vi &A, int k){
    int cnt = 0;
    int crntSum = 0; // follow prefix Sum approach
    unordered_map<int,int> mp;
    mp[0] = 1;
    for(int x : A){
        crntSum += x;
        int c = crntSum - k; // complement lookup
        if(mp.find(c) != mp.end()){
            cnt += mp[c];
        }
        mp[crntSum]++; 
    }
    return cnt;
}

// Product Prefix and Suffix Technique
// Product of array except self
void productWithoutSelf(vi &A){
    vi result(A.size());
    int lft = 1;
    for(int i = 0;i < A.size();i++){
        result[i] = lft;
        lft *= A[i];
    }
    int rgt = 1;
    for(int i = A.size() - 1;i >= 0;i--){
        result[i] *= rgt;
        rgt *= A[i];
    }
    for(int x : result){
        cout << x << endl;
    }
} 



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> A = {1,1,1};
    vector<int> ans = prefixSum(A);
    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;
    cout << subarraySum(A,2);
    cout << endl;
    cout << subarraySumOptim(A,2);
    cout << endl;
    vi B = {2,3,2,5};
    productWithoutSelf(B);
    vi C = {1,3,7,2};
    rangeSumQuery(C,3);
    return 0;
}