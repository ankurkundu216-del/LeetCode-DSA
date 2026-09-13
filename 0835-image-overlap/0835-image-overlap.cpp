#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int countOverlaps(vector<vector<int>>& img1, vector<vector<int>>& img2, int rowOff, int colOff){
        int n=img1.size();
        int cnt=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // find indices of img2 from img1 ka indices[i][j]
                /*
                A[i][j] -> B[i+rowOff][j+colOff]
                */

                int img2_i = i+rowOff;
                int img2_j = j+colOff;

                if(img2_i<0 || img2_i>=n || img2_j<0 || img2_j>=n){
                    continue;
                }
                if(img1[i][j]==1 && img2[img2_i][img2_j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=img1.size();
        // nxn matrix
        // row = n
        // col = n
        int maxOverlap=0;

        for(int rowOff=-n+1; rowOff<n; rowOff++){
            for(int colOff=-n+1; colOff<n; colOff++){
                int cnt=countOverlaps(img1, img2, rowOff, colOff);
                
                maxOverlap=max(maxOverlap, cnt);
            }
        }
        return maxOverlap;
    }
};