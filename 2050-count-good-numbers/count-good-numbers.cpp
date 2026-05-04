class Solution {
public: 
    long long fastExponentiation(long long base, long long exponent) {

        long long result = 1;
        const long long MOD = 1000000007;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (base * result) % MOD;
                exponent--;
            }
            base = (base * base) % MOD;
            exponent = exponent / 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {

        long long evenPos = 0;
        long long oddPos = 0;

        const long long MOD = 1000000007;
        
        if (n % 2 == 0) {
            evenPos = n / 2;
            oddPos = n / 2;
        } 
        else {
            evenPos = (n + 1) / 2;
            oddPos = (n - 1) / 2;
        }

        long long result = (fastExponentiation(5, evenPos) * fastExponentiation (4, oddPos)) % MOD;
        return (int)result;
    }
};