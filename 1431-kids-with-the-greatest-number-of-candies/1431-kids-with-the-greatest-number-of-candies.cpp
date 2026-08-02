#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {

public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int max_can = *max_element(candies.begin(),candies.end());
        vector<bool> result;
        result.reserve(candies.size());
        for(int candy : candies){
            result.push_back(candy+extraCandies >= max_can);
        }    
        return result;
    }
};