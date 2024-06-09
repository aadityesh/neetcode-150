#define MOD 1000000007
class Solution {
public:
    long power(long x, long n) {
        // x = x % MOD;
        if (n == 0)
            return 1;

        long temp = power(x, n / 2);

        if (n & 1) {
            return (x * temp * temp) % MOD;
        } else {
            return (temp * temp) % MOD;
        }
    }
    int countGoodNumbers(long long n) {

        /*long long int even = 1;
        long long int odd = 1;

        for (int i = 0; i < n; i++) {

            if(i % 2 == 0) even = (even * 5) % MOD;
            else  odd = (odd * 4) % MOD;;

        }
        long long int res = (even * odd) % MOD;
        return res;*/

        // Optimal
        long countOfEven = n / 2;
        long countOfOdd = n - countOfEven;

        return ((power(4, countOfEven) % MOD) * (power(5, countOfOdd) % MOD)) %
               MOD;
        cout << power(2, 9) << endl;

        // return 0;
    }
};