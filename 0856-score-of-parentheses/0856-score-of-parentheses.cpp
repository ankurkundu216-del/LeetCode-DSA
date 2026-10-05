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
        stack<int> st; st.push(0); // Base start

        for(char c : s) {
            if(c=='(') {
                st.push(0);
            }else {
                int v= st.top();
                st.pop();

                int val = max(2*v,1);
                st.top() += val;
            }
        }
        return st.top();
    }
};