#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<int> vec = nums;
        sort(begin(vec), end(vec));

        int grp = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = grp;

        unordered_map<int, list<int>> groupToList;
        groupToList[grp].push_back(vec[0]);

        for (int i = 1; i < n; i++) {
            if (vec[i] - vec[i - 1] > limit) {
                grp += 1;
            }
            numToGroup[vec[i]] = grp;
            groupToList[grp].push_back(vec[i]);
        }

        // Build the answer - Merge the groups
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int g = numToGroup[num];
            res[i] = groupToList[g].front();
            groupToList[g].pop_front();
        }

        return res;
    }
};