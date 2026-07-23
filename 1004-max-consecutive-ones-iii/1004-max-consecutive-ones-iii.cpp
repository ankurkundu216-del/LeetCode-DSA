class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0, right=0;
        int max_ones=0;
        int zero_cnt=0;
        for(right=0; right<n; right++){
            if(nums[right]==0){
                zero_cnt++;
            }
            while(zero_cnt>k){
                if(nums[left]==0){
                    zero_cnt--;
                }
                left++;
            }
            max_ones = max(max_ones,right-left+1);
        }
        return max_ones;
    }
};