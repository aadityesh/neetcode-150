class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        double ans = 0;

        vector<int> merge;
        int left = 0;
        int right = 0;

        while (left < n && right < m) {

            if (nums1[left] <= nums2[right])
                merge.push_back(nums1[left++]);
            else
                merge.push_back(nums2[right++]);

        }

        while (left < n)
            merge.push_back(nums1[left++]);

        while (right < m)
            merge.push_back(nums2[right++]);

        int q = merge.size();

        if (q % 2 != 0)
            return double(merge[q / 2]);

        else {
            int idx = q / 2;
            return double(merge[idx] + merge[idx - 1]) / 2.0;
        }
    }
};