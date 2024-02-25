class Solution {
public:
    int mySqrt(int x) {

        if (x == 0)
            return 0;

        int i = 1;
        int j = x;
        int mid = 0;

        while (i <= j) {
            mid = i + ((j - i) / 2); // ensure theres no overflow

            if (mid <= (x / mid) && (mid + 1) > (x / (mid + 1))) // 1...mid... x
                return mid;

            else if (mid > (x / mid))
                j = mid - 1;

            else
                i = mid + 1;
        }

        return j;
    }
};