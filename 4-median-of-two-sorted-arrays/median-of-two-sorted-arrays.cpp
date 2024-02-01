class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Brute
        /*
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
        }*/

        // Better

        int n = nums1.size();
        int m = nums2.size();

        int left = 0;
        int right = 0;

        int ele1 = -1;
        int ele2 = -1;

        int req_index2 = (n + m) / 2;
        int req_index1 = req_index2 - 1;

        int cnt = 0;
        while (left < n && right < m) {

            if (nums1[left] < nums2[right]) {

                if (cnt == req_index1)
                    ele1 = nums1[left];
                if (cnt == req_index2)
                    ele2 = nums1[left];

                left++;
                cnt++;
            }

            else {

                if (cnt == req_index1)
                    ele1 = nums2[right];
                if (cnt == req_index2)
                    ele2 = nums2[right];
                right++;
                cnt++;
            }
        }

        while (left < n) {

            if (cnt == req_index1)
                ele1 = nums1[left];
            if (cnt == req_index2)
                ele2 = nums1[left];

            left++;
            cnt++;
        }
        while (right < m) {
            if (cnt == req_index1)
                ele1 = nums2[right];
            if (cnt == req_index2)
                ele2 = nums2[right];
            right++;
            cnt++;
        }

        if ((n + m) % 2 != 0)
            return ele2;
        else
            return double(ele1 + ele2) / 2.0;
    }
};