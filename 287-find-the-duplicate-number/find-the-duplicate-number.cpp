class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Brute
        /*
        unordered_map<int, int> umap;
        for (auto i : nums) {
            umap[i]++;
            if (umap[i] > 1)
                return i;
        }
        return -1;
        */

        // Optimal

        int slow = nums[0];
        int fast = nums[nums[0]];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};