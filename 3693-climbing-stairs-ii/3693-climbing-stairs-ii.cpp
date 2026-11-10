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
    int climbStairs(int n, vector<int>& costs) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int a=0, b=0, c=0;
        for(int i=0; i<n; ++i){
            int nxt = min({a+9, b+4, c+1})+costs[i];
            a=b;
            b=c;
            c=nxt;
        }
        return c;
    }
};