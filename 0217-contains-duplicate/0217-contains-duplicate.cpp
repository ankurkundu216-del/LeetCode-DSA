#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // Hash Map
        unordered_map<int, int> seen;
        for(int num : nums){
            if(seen[num] >= 1){
                return true;
            }
            seen[num]++;
        }
        return false;

        /*
        // Hash set
        unordered_set<int> seen;
        for(int num : nums){
            if(seen.count(num)>0) return true;
            seen.insert(num);
        }return false;*/
        /*
        // Sorting
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]) return true;
        }
        return false;*/
        /* Brute Force Approach
        int n=nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]==nums[j]){
                    return true;
                }
            }
        }
        return false;*/
    }
};