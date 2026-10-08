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
    string removeOuterParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string result = "";
        int level = 0;

        for(char ch : s) {
            if(ch == '(') {
                if(level>0) result += ch;
                level++;
            } else if(ch == ')') {
                level--;
                if(level>0) result += ch;
            }
        }
        return result;
    }
};