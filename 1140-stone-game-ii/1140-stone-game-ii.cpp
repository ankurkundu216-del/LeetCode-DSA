#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = piles.size();

        vector<int> suffixSum(n+1,0);
        for(int i=n-1; i>=0; i--) {
            suffixSum[i] = suffixSum[i+1]+piles[i];
        }

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int i=n-1; i>=0; i--){
            for(int M=1; M<=n; M++){
                if(i+2*M >= n){
                    dp[i][M] = suffixSum[i];
                    continue;
                }
                int maxStones=0;
                for(int x=1; x<=2*M; x++){
                    maxStones = max(maxStones,suffixSum[i]-dp[i+x][max(M,x)]);
                }
                dp[i][M] = maxStones;
            }
        }
        return dp[0][1];
    }
};