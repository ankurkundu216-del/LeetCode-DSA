#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n>m) return false; // Base case

        sort(s1.begin(), s1.end());
        
        for(int i=0; i<=m-n; i++) {
            string substring = s2.substr(i, n);

            sort(substring.begin(),substring.end());

            if(s1 == substring) {
                return true;
            }
        }
        return false;
    }
};
/*
// THE BRUTE FORCE APPROACH
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    bool res;

    void solve(int idx, string& s1, string& s2) {
        if (idx==n){
            if(s2.find(s1) != string::npos){
                res = true;
            }
            return;
        }
        for(int i=idx; i<n; i++){
            swap(s1[i], s1[idx]);
            solve(idx+1, s1, s2);
            swap(s1[i], s1[idx]);

            if(res==true)return;
        }
    }
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        n = s1.length();
        res = false;
        solve(0, s1, s2);
        return res; 
    }
};*/