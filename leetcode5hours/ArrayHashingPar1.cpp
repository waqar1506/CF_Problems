#include <bits/stdc++.h>
using namespace std;
// Concept: Hashset for existence checks
// Approaches : Linear Search, Binary Search, Hashset

// Linear Search O(n)

// Binary Search O(log(n))

// Hashset O(1)
void duplicate_hashset(vector<int> &A){
    set<int> st;
    // If we are aiming for O(1) average time existence checking, use
    // unordered_set instead of set
    unordered_set<int> st_d;
    for(int x : A){
        if(st.find(x) != st.end()){
            cout << "Present\n";
            return;
        }
        st.insert(x);
    }
    cout << "Not Duplicate\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> A = {5,3,5,9,1};
    duplicate_hashset(A);
    return 0;
}