class Solution {
public:
    int reverse(int x) {

        int lastDigit = 0;
        int res = 0;

        while (x) {

            lastDigit = x % 10;

            if (res > (INT_MAX / 10) || res == (INT_MAX / 10) && lastDigit > 7)
                return 0;

            if (res < (INT_MIN / 10) || res == (INT_MIN / 10) && lastDigit < -8)
                return 0;

            res = (res * 10) + lastDigit;
            x /= 10;
        }
        // cout << INT_MAX << " " << INT_MIN << endl;
        return res;
    }
};