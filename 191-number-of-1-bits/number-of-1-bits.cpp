class Solution {
public:
    int hammingWeight(int n) {
        /*
        - Brute
          - convert n into binary string
          - count # of ones
        */

        int cnt = 0;
        while (n) {
            if (n & 1)
                cnt++;
            n = n >> 1;
        }
        return cnt;
    }
};