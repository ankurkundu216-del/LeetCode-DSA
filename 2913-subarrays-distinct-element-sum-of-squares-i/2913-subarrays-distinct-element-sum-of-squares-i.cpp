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
    int sumCounts(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size(), res=0;
        for(int i=0; i<n; i++){
            unordered_set<int>s;
            for(int j=i; j<n; j++){
                s.insert(nums[j]);
                res += s.size()*s.size();
            }
        }
        return res;
    }
};