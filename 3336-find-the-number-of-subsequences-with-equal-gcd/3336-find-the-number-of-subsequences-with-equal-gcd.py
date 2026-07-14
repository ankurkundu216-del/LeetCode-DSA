import math

class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        memo = {}
        n = len(nums)
        MOD = 10**9+7

        def dp(i,gcd1,gcd2):
            # Agar array ke bahar nikal gaye then base case 
            if i==n:
                if gcd1>0 and gcd1==gcd2:
                    return 1
                return 0
            
            # Agar humne yeh state pehle solve ki hui hain then memorization
            state = (i,gcd1,gcd2)
            if state in memo:
                return memo[state]

            # 3 choices hain humare paas
            # Choice 1: Number ko skip kar
            #(i+1 pe jao, gcd same rahega)
            skip = dp(i+1,gcd1,gcd2)

            # Choice 2: Number ko group 1 mein daalo naya gcd banega
            # math.gcd(gcd1,nums[i])
            grp1 = dp(i+1,math.gcd(gcd1,nums[i]),gcd2)

            # Choice 3:  Number ko group 2 mein daalo naya gcd banega
            # math.gcd(gcd2,nums[i])
            grp2 = dp(i+1,gcd1,math.gcd(gcd2,nums[i]))

            memo[state] = (skip+grp1+grp2)%MOD

            return memo[state]

        return dp(0,0,0) 