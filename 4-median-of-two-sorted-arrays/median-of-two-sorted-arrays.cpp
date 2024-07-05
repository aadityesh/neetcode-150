class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);

        // Assuming nums1 to be always the smallest
        int m = nums1.size();
        int n = nums2.size();

        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = m;

        while (low <= high) {

            // mid
            // P denotes number of elements taken from either nums1/nums2
            int Px = (low + (high - low) / 2);
            int Py = (m + n + 1) / 2 - Px;

            // Denotes left half
            int x1 = (Px == 0) ? INT_MIN : nums1[Px - 1];
            int x2 = (Py == 0) ? INT_MIN : nums2[Py - 1];

            // Denotes right half
            int x3 = (Px == m) ? INT_MAX : nums1[Px];
            int x4 = (Py == n) ? INT_MAX : nums2[Py];

            if (x1 <= x4 && x2 <= x3) {

                if ((m + n) % 2 == 1) {
                    return max(x1, x2) / 1.0;
                }

                else {
                    return (max(x1, x2) + min(x3, x4)) / 2.0;
                }
            }

            else if (x1 > x4) {
                high = Px - 1;
            }

            else {
                low = Px + 1;
            }
        }

        return -1;
    }
};