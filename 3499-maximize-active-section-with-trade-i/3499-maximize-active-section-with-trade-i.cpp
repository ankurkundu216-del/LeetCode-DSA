class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int initial_ones = 0;
        vector<int> zero_blocks;

        int n = s.length();
        int i=0;

        while(i<n){
            if(s[i] == '1'){
                initial_ones++;
                i++;
            } else {
                int count = 0;
                while(i<n && s[i]=='0'){
                    count++;
                    i++;
                }
                zero_blocks.push_back(count);
            }
        }
        if (zero_blocks.size() < 2) {
            return initial_ones;
        }
        int max_zero_gain = 0;
        for(size_t k=0; k+1<zero_blocks.size();++k){
            max_zero_gain = max(max_zero_gain, zero_blocks[k]+zero_blocks[k+1]);
        }
        return initial_ones + max_zero_gain;
    }
};