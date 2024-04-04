class Solution {
public:
    int findPeakElement(vector<int>& a) {

        int n = a.size();
        if (n == 1)
            return 0;
        if (a[0] > a[1])
            return 0;
        if (a[n - 2] < a[n - 1])
            return n - 1;

        int low = 1;
        int high = n - 2;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid - 1] < a[mid] && a[mid] > a[mid + 1])
                return mid;

            if (a[mid - 1] < a[mid])
                low = mid + 1;

            else
                high = mid - 1;
        }

        // dummy return
        return -1;
    }
};