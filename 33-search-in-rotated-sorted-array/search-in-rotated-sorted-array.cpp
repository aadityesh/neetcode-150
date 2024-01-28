class Solution {
public:
    int search(vector<int>& a, int target) {

        int n = a.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (a[mid] == target) {
                ans = mid;
                return ans;
            }

            if (a[low] <= a[mid])

                if (a[low] <= target && target <= a[mid]) {
                    high = mid - 1;
                } else
                    low = mid + 1;
            else {

                if (a[mid] <= target && target <= a[high]) {
                    low = mid + 1;
                } else
                    high = mid - 1;
            }
        }
        return ans;
    }
};