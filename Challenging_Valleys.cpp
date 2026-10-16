#include <bits/stdc++.h>
using namespace std;
void solve(){
    long long n;
    cin >> n;
    vector<long long> v;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        if(i == 0 || x != v.back()){
            v.push_back(x);
        }
    }
    long long nvalley = 0;
    for(int i = 0;i < v.size();i++){
        if((i == 0 || v[i-1] > v[i]) && (i == v.size()-1 || v[i] < v[i+1]))
        {
            nvalley++;
        }
        
    }
    if(nvalley==1){
        cout <<"YES\n";
    }else{
        cout <<"NO\n";
    }
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}