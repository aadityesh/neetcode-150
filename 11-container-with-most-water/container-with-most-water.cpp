class Solution {
public:
    int maxArea(vector<int>& a) {

        int n = a.size();
        // Brute
        /*
        int area = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int height = min(a[i], a[j]);
                area = max(area, height * (j - i));
            }
        }

        return area;
        */

        // Optimal
        int res = 0;
        int left = 0;
        int right = n - 1;

        while (left < right) {

            int area = min(a[left], a[right]) * (right - left);
            res = max(res, area);

            if (a[left] <= a[right])
                left++;
            else
                right--;
        }

        return res;
    }
};