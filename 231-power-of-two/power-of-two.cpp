class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n <= 0) return false;

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

        return cnt == 1;
    }
};