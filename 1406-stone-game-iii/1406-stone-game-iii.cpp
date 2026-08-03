class Solution {
public:
    int n;
    vector<int> memo;

    int solve(vector<int>& stoneValue, int i) {
        if (i >= n) return 0;
        
        if (memo[i] != -1e9) return memo[i];

        int res = stoneValue[i] - solve(stoneValue, i + 1);

        if (i + 1 < n) {
            res = max(res, stoneValue[i] + stoneValue[i + 1] - solve(stoneValue, i + 2));
        }
        if (i + 2 < n) {
            res = max(res, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - solve(stoneValue, i + 3));
        }

        return memo[i] = res;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        memo.assign(n, -1e9);

        int diff = solve(stoneValue, 0);

        if (diff < 0) return "Bob";
        if (diff > 0) return "Alice";
        return "Tie";
    }
};