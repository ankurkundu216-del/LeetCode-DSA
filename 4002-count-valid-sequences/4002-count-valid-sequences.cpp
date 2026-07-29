class Solution {
private:
    const int MOD = 1e9 + 7;

    long long power(long long base, long long exp){
        long long res = 1;
        base %= MOD;
        while(exp>0){
            if(exp%2 == 1) res = (res*base)%MOD;
            base = (base*base) % MOD;
            exp /= 2;
        }
        return res;
    }
    long long modInverse(long long n){
        return power(n, MOD-2);
    }
    long long nCr(int n, int r){
        if(r<0 || r>n) return 0;
        if(r==0 || r==n) return 1;

        long long num = 1, den = 1;
        for(int i=0; i<r; ++i){
            num = (num*(n-i)) % MOD;
            den = (den*(i+1)) % MOD;
        }
        return (num*modInverse(den)) % MOD;
    }
public:
    int countValidSequences(int n, int k) {
        long long totalSequences = nCr(n-1, k-1);
        long long oddSequences = 0;
        if(n>=k && (n-k)%2==0){
            int m = (n-k)/2;
            oddSequences = nCr(m+k-1, k-1);
        }
        long long ans = (totalSequences - oddSequences + MOD) % MOD;
        return ans;
    }
};