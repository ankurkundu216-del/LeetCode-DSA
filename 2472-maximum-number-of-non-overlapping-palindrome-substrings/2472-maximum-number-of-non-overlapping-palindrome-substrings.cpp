#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while(l<r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = s.length();
        vector<int> dp(n+1, 0);

        for(int i=0; i<n; ++i) {
            dp[i+1] = dp[i];
            if(i+1 >= k && isPalindrome(s, i-k+1, i)) {
                dp[i+1] = max(dp[i+1], dp[i-k+1]+1);
            }
            if(i+1>=k+1 && isPalindrome(s, i-k, i)) {
                dp[i+1] = max(dp[i+1], dp[i-k]+1);
            }
        }
        return dp[n];
    }
};