#include <bits/stdc++.h>
using namespace std;
// T1: Hashset for existence checks
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

void existenceCheck_Set(vector<int> &A,int t){
    unordered_set<int> st(A.begin(),A.end());
    if(st.find(t)!=st.end()){
        cout << t << " Present\n";
    }else{
        cout << t << " is not Present\n";
    }
}

// --------------------------------x------------------------------x-----------------
// T2: Hash map for frequency and counting
void freqarray_counting(vector<int> &A){
    unordered_map<int,int> mp;
    for(int x : A){
        mp[x]++;
    }
    for(auto i : mp){
        cout << i.first << " " << i.second << endl;
    }
}

// -----------------------x---------------------------x-------------------------------
// T3: Complement lookup pattern
void twoSum(vector<int> &A, int t){
    unordered_map<int,int> mp;
    for(int i = 0;i < A.size();i++){
        int x = t - A[i];
        if(mp.find(x) != mp.end()){
            cout << mp[x] << " " << i << endl;
            return;
        }
        mp[A[i]] = i;
    }
    cout << "Not Satisfy";
}

// ----------------x-----------------x----------------------------x------------------
// Generalizes the complement lookup pattern
// Problem: Pair with equal digit sum
int digitSum(int n){
    int sm = 0;
    while(n > 0){
        sm += n % 10;
        n/=10;
    }
    return sm;
}
void pairEqualDigit(vector<int> &A){
    unordered_map<int,int> mp;
    int ans = -1;
    for(int i = 0;i < A.size();i++){
        int dSum = digitSum(A[i]);
        if(mp.count(dSum)){
            ans = max(ans, A[i] + mp[dSum]);
        }
        mp[dSum] = max(mp[dSum],A[i]);
    }
    cout << ans << endl;
}



// --------------------------x------------------------------x-----------------------x---
// Grouping by normalized key
// Group Anagram
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagram(vector<string> ststr) {
    unordered_map<string, vector<string>> A;

    for (string s : ststr) {
        string k = s;
        sort(k.begin(), k.end());
        A[k].push_back(s);
    }

    vector<vector<string>> stA;

    for (auto& it : A) {
        stA.push_back(it.second);
    }

    return stA;
}
// Anagram Checking
bool anagram(string s,string t){
    unordered_map<char,int> mp;
    for(char x : s){
        mp[x]++;
    }
    if(s.size() != t.size()){
        return false;
    }else{
        for(int i = 0;i < s.size();i++){
            if(mp.count(t[i])){
                mp[t[i]]--;
                if(mp[t[i]] == 0){
                    mp.erase(t[i]);
                }
            }
        }
        if(mp.size() == 0){
            return true;
        }else{
            return false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    vector<int> A = {1,2};
    vector<int> B = {16,71,13,41,34,25};
    duplicate_hashset(A);
    existenceCheck_Set(A,152);
    freqarray_counting(A);
    twoSum(A,3);
    pairEqualDigit(B);
    cout << anagram("omeeblkaccw","welcomebackkk");
    return 0;
}