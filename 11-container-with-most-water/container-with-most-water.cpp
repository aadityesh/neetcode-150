class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();
        int L = 0;
        int R = n - 1;
        int res = 0;
        int current = 0;

        while (L < R) {

            current = min(height[L], height[R]) * (R - L);
            res = max(res, current);

            if (height[L] <= height[R])
                L++;
            else
                R--;
        }

        return res;
    }
};