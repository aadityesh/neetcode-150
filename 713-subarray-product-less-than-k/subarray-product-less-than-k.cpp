class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {

        // Brute (TLE)
        /*
        int n = a.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            long long int res = 1;
            for (int j = i; j < n; j++) {
                res *= a[j];
                if (res < k)
                    cnt++;
            }
        }
        return cnt;
        */

        // Optimal
        int n = a.size();
        int left = 0;
        int right = 0;
        int cnt = 0;
        long long res = 1;

        if (k == 0)
            return 0;

        while (right < n) {
            res *= a[right];
            while (res >= k && left <= right) {
                res = res / a[left];
                left++;
            }
            cnt += (right - left + 1);
            right++;
        }

        return cnt;
    }
};