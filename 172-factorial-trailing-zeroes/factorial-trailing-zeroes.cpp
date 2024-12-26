class Solution {
public:
    int trailingZeroes(int n) {
        if (n <= 4)
            return 0;
        int cnt = 0;
        while ((n / 5) >= 1) {
            cnt += (n / 5);
            n /= 5;
        }
        return cnt;
    }
};