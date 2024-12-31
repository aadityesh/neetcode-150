class Solution {
public:
    int hammingWeight(int n) {
        /*
        - Brute
          - convert n into binary string
          - count # of ones
        */

        /* int cnt = 0;
         while (n) {
             if (n & 1)
                 cnt++;
             n = n >> 1;
         }
         return cnt;
         */

        int table[256];
        table[0] = 0;

        for (int i = 0; i < 256; i++) {
            table[i] = table[i / 2] + (i % 2);
        }

        int cnt = 0;

        cnt = table[n & 0xff];
        n = n >> 8;

        cnt += table[n & 0xff];
        n = n >> 8;

        cnt += table[n & 0xff];
        n = n >> 8;

        cnt += table[n & 0xff];
        n = n >> 8;

        return cnt;
    }
};