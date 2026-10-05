/*
             _|_
            | U |
            |   |  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
            |___|  |==============================|===~
                   ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~
         "Everyone is against me, Madhav...
            ...then everyone will lose."
*/

#include<stdio.h>
using namespace std;
class Solution {
public:
    int scoreOfParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans=0;
        int depth = 0;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') {
                depth++;
            }else {
                depth--;
                if(s[i-1] == '(') {
                    ans += (1<<depth);
                }
            }
        }
        return ans;
    }
};