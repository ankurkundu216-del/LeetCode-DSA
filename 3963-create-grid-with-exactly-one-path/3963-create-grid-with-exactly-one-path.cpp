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
    vector<string> createGrid(int m, int n) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        vector<string> res(m - 1, "." + string(n - 1, '#'));
        res.push_back(string(n, '.'));
        return res;
    }
};