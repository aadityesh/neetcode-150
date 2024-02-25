class Solution {
public:
    int mySqrt(int x) {

        if (x == 0)
            return 0;

        int left = 1;
        int right = x;
        int mid = 0;

        while (left <= right) {
            mid = left + ((right - left) / 2); // ensure theres no overflow

            if (mid == (x / mid)) // 1...mid... x
                return mid;

            else if (mid > (x / mid))
                right = mid - 1;

            else
                left = mid + 1;
        }

        return right;
    }
};