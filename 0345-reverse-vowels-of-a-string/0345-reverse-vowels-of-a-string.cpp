class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length()-1;
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        while(left<right){
            while(left<right && vowels.count(s[left])==0){
                left++;
            }
            while(left<right && vowels.count(s[right])==0){
                right--;
            }
            if(left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};