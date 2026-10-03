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
    int longestValidParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = s.length();
        int op=0;
        int cl=0;

        // Left to Right
        int res = 0;

        for(int i=0; i<n; i++) {
            if(s[i]=='(') op++;
            else cl++;

            if(op == cl) {
                res = max(res, op+cl);
            } else if(cl>op) {   // left to right
                op=cl=0;
            }
        }

        // Righr to Left
        op=0;
        cl=0;
        for(int i=n-1; i>=0; i--) {
            if(s[i]=='(') op++;
            else cl++;

            if(op == cl) {
                res = max(res, op+cl);
            } else if(cl<op) {   // left to right
                op=cl=0;
            }
        }
        return res;
    }
};