#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();

        long long total_sum = 0;
        for(int num : nums) {
            total_sum += num;
        }

        long long target = total_sum - x;

        // Edge Cases
        if(target < 0) return -1;
        if(target == 0) return n;

        int left = 0;
        long long curr_sum = 0;
        int max_len = -1;

        for (int right=0; right<n; ++right) {
            curr_sum += nums[right];

            while(curr_sum > target && left<=right) {
                curr_sum -= nums[left];
                left++;
            }
            if(curr_sum == target) {
                max_len = max(max_len, right-left+1);
            }
        }
        return (max_len != -1) ? (n-max_len) : -1;
    }
};