class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int times = 32;
        while (times--) {
            res = (res << 1) | (n & 1);
            n = n >> 1;
        }
        return res;
    }
};