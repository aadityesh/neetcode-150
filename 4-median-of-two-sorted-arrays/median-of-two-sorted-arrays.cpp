class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        double ans = 0;
        // if(n <= 0) return nums2[0];
        // if(m <= 0) return nums1[0];

        vector<int> merge;
        for (auto i : nums1)
            merge.push_back(i);

        for (auto i : nums2)
            merge.push_back(i);

        sort(merge.begin(), merge.end());

        int q = merge.size();

        if (q == 1)
            return merge[0];

        else if (q == 2)
            return double(merge[0] + merge[1]) / 2.0;

        else if (q % 2 != 0)
            return double(merge[q / 2]);

        else {
            int idx = q / 2;
            return double(merge[idx] + merge[idx - 1]) / 2.0;
        }
    }
};