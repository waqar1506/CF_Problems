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


void solve() {
    int N;cin >> N;

    // Doubly linked list to maintain the order of elements
    list<int> A;

    // Maps each element's value to its iterator in the list
    // This allows us to find elements in O(1) average time
    unordered_map<int,list<int>::iterator> position;
    
    for(int i = 0;i < N;i++){
        int e;cin >> e;
        // Insert the element at the end of the list
        A.push_back(e);
        // Store an iterator pointing to the newly inserted element
        position[e] = prev(A.end());
    }

    int Q;cin >> Q;
    while(Q--){
        int opt;cin >> opt;
        // Query format: 1 p c
        // Insert c immediately after element p
        if(opt == 1){
            // Query format: 1 p c
            // Insert c immediately after element p
            int p,c;
            cin >> p >> c;
            
            // Get the iterator pointing to element p
            auto it = position[p];

            // Insert c immediately after p
            // insert() returns an iterator pointing to the new element
            auto insertx = A.insert(next(it),c);

            // Store the iterator of the newly inserted element
            position[c] = insertx;
        }else if(opt == 2){
            int r;
            // Query format: 2 r
            // Remove element r from the list
            cin >> r;

            // Erase element r using its stored iterator
            A.erase(position[r]);

            // Remove r from the hash map
            position.erase(r);
        }
    }
    for(int x : A){
        cout << x << " ";
    }
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