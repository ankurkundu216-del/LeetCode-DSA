#include<bits/stdc++.h>
using namespace std;
class Solution {
    int memo[2][101][101];

    int n;

    int solveForAlice(vector<int>& piles, int person, int i, int M){

        if(i==n) return 0;

        if(memo[person][i][M] != -1) return memo[person][i][M];

        int result = (person == 1) ? -1 : INT_MAX;

        int stones =0;

        for(int x=1; x <= min(2*M,n-i); x++){

            stones += piles[i+x-1];

            if(person == 1) {
                result = max(result, stones + solveForAlice(piles, 0, i+x, max(M, x)));
            } else {
                result = min(result,solveForAlice(piles,1,i+x,max(M,x)));
            }
        }
        return memo[person][i][M] = result;
    }
public:
    int stoneGameII(vector<int>& piles) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        memset(memo, -1, sizeof(memo));
        n = piles.size();

        return solveForAlice(piles,1,0,1);
    }
};