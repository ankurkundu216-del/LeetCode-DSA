#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkDivisibility(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int dig_sum=0;
        int dig_prod=1;
        int org=n;

        while(n>0){
            int dig = n%10;
            n/=10;

            dig_sum+=dig;
            dig_prod*=dig;
        }
        return org % (dig_sum+dig_prod)==0;
    }
};