class Solution {
public:
    int getSum(int a, int b) {
        unsigned int temp = 0;
        while (b) {
            temp = (a & b);
            a = a ^ b;
            b = temp << 1;
        }
        return a;
    }
};