class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        int times = 32;
        while (times) {
            reversed = reversed << 1;
            reversed = reversed | (n & 1);
            n = n >> 1;
            times--;
        }

        return reversed;
    }
};