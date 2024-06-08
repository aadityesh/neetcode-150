#define MOD 1000000007
class Solution {
public:
    long long int power(long long int x, long long int n) {
        x = x % MOD;
        if (n == 0)
            return 1;

        if (n & 1) {
            return (x * power((x * x) % MOD, n / 2)) % MOD;
        } else {
            return (power((x * x) % MOD, n / 2)) % MOD;
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
        long long int countOfEven = n / 2;
        long long int countOfOdd  = n - countOfEven;

        return ((power(4, countOfEven) % MOD) * (power(5, countOfOdd) % MOD)) %
               MOD;
        cout << power(2, 9) << endl;

        // return 0;
    }
};