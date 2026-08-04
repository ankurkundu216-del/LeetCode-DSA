#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(nums.size() <= 2) return nums.size();
        int i = 2;
        for(int j=2; j<nums.size(); j++){
            if(nums[j] != nums[i-2]){
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};