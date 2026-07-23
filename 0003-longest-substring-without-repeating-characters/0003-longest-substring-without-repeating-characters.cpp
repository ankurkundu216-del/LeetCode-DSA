class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> last_seen(128, -1);
        int max_len = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            char current = s[right];
            
            if (last_seen[current] >= left) {
                left = last_seen[current] + 1;
            }
            
            last_seen[current] = right;
            max_len = std::max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};