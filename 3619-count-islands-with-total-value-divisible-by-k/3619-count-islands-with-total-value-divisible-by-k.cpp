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
#define ll long long
class Solution {
    int m,n;
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    ll dfs(int i, int j, vector<vector<int>>& grid){
        ll sum = grid[i][j];
        grid[i][j]=0;
        // so for top the (i,j) will move to (i-1,j)
        // for bottom the (i,j) will move to (i+1,j)
        // for left the (i,j) will move to (i,j-1)
        // for right the (i,j) will move to (i,j+1)
        // so we need to apply dfs to all of that like dfs(i-1,j), dfs(i+1,j) and so on which is gonna be lengthy
        // so we will create a directions vector to simplify that such as {(0,-1),(0,1),(1,0),(-1,0)}
        for(vector<int>& dir : directions) {
            int i_ = i+dir[0];
            int j_ = j+dir[1];
            if(i_>=0 && i_<m && j_>=0 && j_<n && grid[i_][j_]>0){
                sum += dfs(i_,j_,grid);
            }
        }
        return sum;

    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        m = grid.size();
        n = grid[0].size();
        int count=0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] > 0) {
                    ll sum = dfs(i,j,grid);
                    if(sum%k == 0){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};