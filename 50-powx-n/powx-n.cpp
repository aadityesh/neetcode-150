class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        long pow = abs(n);

        while(pow) {

            if(pow & 1) {
                res = res * x;
                pow = pow - 1;
            }

            else {
                x = x * x;
                pow /= 2;
            }

        }

        if(n < 0) res = 1.0 / res;

        return res;

    }
};