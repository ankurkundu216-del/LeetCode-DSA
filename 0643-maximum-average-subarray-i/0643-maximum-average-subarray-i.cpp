#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // fast i/o
        ios_base::sync_with_stdio(false); cin.tie(NULL);

        int n=nums.size(); //declare the size of array
        
        if(n<k) return -1; // if the array is smaller than window

        int curr_window_sum=0;
        // initialize first window from 0 to k-1
        for(int i=0; i<k; i++){
            curr_window_sum+=nums[i];
        }
        int max_ans = curr_window_sum;

        // slide the window forward from k to n-1
        for(int i=k; i<n; i++){
            curr_window_sum += nums[i];
            curr_window_sum -= nums[i-k];

            max_ans = max(max_ans, curr_window_sum);
        }
        return (double)max_ans/k;
    }
};