
class Solution {
public:
    int findMin(vector<int>& a) {

        // brute - force
        int n = a.size();
        /*
        int mini = nums[0];
        for(int i = 1; i < n; i++) {
           mini = min(mini, nums[i]);
        }
        return mini;
        */

        int low = 0;
        int high = n - 1;
        int mini = INT_MAX;

        while (low <= high) {

            int mid = (low + high) / 2;

            if (a[low] <= a[mid]) {
                mini = min(mini, a[low]);
                low = mid + 1;

            } else {

                mini = min(mini, a[mid]);
                high = mid - 1;
            }
        }

        return mini;
    }
};