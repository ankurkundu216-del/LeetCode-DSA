#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=img1.size();

        vector<int> A(n,0);
        vector<int> B(n,0);

        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(img1[i][j]) A[i] |= (1<<j);
                if(img2[i][j]) B[i] |= (1<<j);
            }
        }
        int maxOverlap=0;

        for(int rowShift=-n+1; rowShift<n; ++rowShift){
            for(int colShift=-n+1; colShift<n; ++colShift){
                int currentOverlap=0;
                for(int i=0; i<n; ++i){
                    int img2Row=i+rowShift;
                    if(img2Row<0 || img2Row>=n) continue;
                    int shiftedRowA;
                    if(colShift >= 0){
                        shiftedRowA=A[i]<<colShift;
                    }else{
                        shiftedRowA=A[i]>>(-colShift);
                    }
                    currentOverlap += __builtin_popcount(shiftedRowA & B[img2Row]);
                }
                maxOverlap = max(maxOverlap, currentOverlap);
            }
        }
        return maxOverlap;
    }
};