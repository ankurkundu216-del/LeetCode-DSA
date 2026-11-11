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

class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        if(s.length()!=t.length()) {
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        for(int i=0; i<s.length(); i++) {
            if(s[i]!=t[i]) {
                return false;
            }
        }
      return true;
    }
};