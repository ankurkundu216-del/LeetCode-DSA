#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        std::unordered_map<long long, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        int max_len = 1;
        
        if (freq.count(1)) {
            int count1 = freq[1];
            if (count1 % 2 == 0) {
                count1--;
            }
            max_len = std::max(max_len, count1);
        }
        
        for (auto& [val, count] : freq) {
            if (val == 1) continue;
            
            int current_len = 0;
            long long x = val;
            
            while (freq.count(x) && freq[x] >= 2) {
                current_len += 2;
                x = x * x;
            }
            
            if (freq.count(x) && freq[x] >= 1) {
                current_len += 1;
            } else {
                current_len -= 1;
            }
            
            max_len = std::max(max_len, current_len);
        }
        
        return max_len;
    }
};