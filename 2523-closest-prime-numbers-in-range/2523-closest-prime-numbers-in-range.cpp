class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // Step 1: Sieve of Eratosthenes
        std::vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Step 2: Collect primes in range
        std::vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        
        if (primes.size() < 2) return {-1, -1};
        
        // Step 3: Find closest pair
        int min_diff = INT_MAX;
        std::vector<int> ans = {-1, -1};
        
        for (size_t i = 0; i < primes.size() - 1; i++) {
            int diff = primes[i+1] - primes[i];
            if (diff < min_diff) {
                min_diff = diff;
                ans = {primes[i], primes[i+1]};
            }
            if (min_diff <= 2) return ans; // Early exit optimization
        }
        
        return ans;
    }
};