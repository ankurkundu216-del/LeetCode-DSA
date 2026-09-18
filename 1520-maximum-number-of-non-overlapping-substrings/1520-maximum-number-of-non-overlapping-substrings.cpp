#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = s.length();

        vector<int> st(26, -1);
        vector<int> en(26, 0);
        vector<bool> isValid(26, true);

        vector<string> result;

        for(int i=0; i<n; i++) {
            int idx = s[i] - 'a';

            if(st[idx] == -1) {
                st[idx] = i;
            }
            en[idx] = i;
        }

        for(int c = 0; c < 26; c++) { // checking all characters
            if(st[c] == -1) continue;

            for(int i=st[c]; i<=en[c]; i++) {
                if(st[s[i] - 'a'] < st[c]) {
                    isValid[c] = false;
                    break;
                }
                en[c] = max(en[c], en[s[i]-'a']); 
            }
        }

        int lastTakenStart = INT_MAX;

        for(int i=n-1; i>=0; i--) {
            int c = s[i] - 'a';

            if(!isValid[c]) continue;

            if(i == st[c] && en[c] < lastTakenStart) {
                result.push_back(s.substr(i, en[c]-i+1));
                lastTakenStart = i;
            }
        }
        return result;
    }
};