#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
         string c="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                c.pop_back();
            }else{
                c+=s[i];
            }
            
        }
        return c;
    }
};