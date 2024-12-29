class Solution {
public:
    int getSum(int a, int b) {

/*

        2 - 010        
        1 - 001
        _________
        3 - 011

        7 - 111
        2 - 010
        _______
        9 - 1001
          - 

*/
        int carry = 0;

        while (b) {
            carry = (a & b) << 1;
            a = a ^ b; // partial sum
            b = carry; // carry
        }
        return a;
    }
};