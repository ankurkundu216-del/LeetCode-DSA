/*
             _|_
            | U |
            |   |  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
            |___|  |==============================|===~
                   ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
         "Everyone is against me, Madhav...
            ...then everyone will lose."
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> result;

    bool isValid(string& curr) {
        int cnt=0;
        for(char ch : curr) {
            if(ch == '('){
                cnt++;
            }else {
                cnt--;
            }
            if(cnt <0) return 0;
        }
        return cnt==0;
    }

    void solve(string& curr, int n) {
        //Base Case
        if(curr.length() == 2*n) {
            if(isValid(curr)) {
                result.push_back(curr);
            }
            return;
        }
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();

        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string curr = "";

        solve(curr, n);

        return result;
    }
};