#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(n==0) return 0;
        if(n<=3) return 1;

        string s = "122";
        int read = 2;
        char num = '1';

        while(s.length()<n){
            int cnt = s[read]-'0';
            s.append(cnt,num);
            num = (num=='1')?'2':'1';
            read++;
        }
        int ones=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ones++;
        }
        return ones;
    }
};