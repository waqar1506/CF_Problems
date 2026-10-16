// Concepts: Two Pointers, Greedy
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> vc(n);

        for(int i = 0;i < n;i++){
            cin >> vc[i];
        }

        long long ans = 0;
        for(int i = 0;i < n;i++){
            long long mxEle = -2e18;
            int j = i;
            // c1 -> j should smaller than n
            // c2 -> every jth element and ith element should greater than 0
            // c3 -> every jth element and ith element should less than 0

            // c1 AND (c2 OR c3)
            // If above condition is true then find maximum of neg. and pos. element
            // move j++
            while(j < n and ((vc[j] > 0 and vc[i] > 0) or (vc[j] < 0 and vc[i] < 0))){
                mxEle = max(mxEle,vc[j]);
                j++;
            }
            // If false then
            // Add maximum element to ans
            // then reach the ith index to jth position
            ans += mxEle;
            i = j - 1;
        }

        cout << ans << endl;
    }
    return 0;
}