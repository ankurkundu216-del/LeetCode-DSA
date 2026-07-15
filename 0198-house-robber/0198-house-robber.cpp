class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();

        // Base Cases
        if (n==0) return 0;
        if (n==1) return nums[0];
        if (n==2) return max(nums[0],nums[1]);

        // DP banao haar ghar ka max profit store karne keliye
        vector<int> dp(n);
        
        // Shuruati ghaaro ka max profit 
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);

        for(int i=2; i<n; i++) {
            // Formula: max(aaj chori ki + ek ghar chhod kar profit, aaj chori nhi ki)
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};