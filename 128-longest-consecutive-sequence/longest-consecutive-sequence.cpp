class Solution {
public:
    /* // Brute-force approach
    bool ls(vector<int>& nums, int key) {
        for (int i : nums) {
            if (i == key)
                return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        int res = 0, cnt = 0, x = 0;

        for (int i = 0; i < n; i++) {
            x = nums[i];
            cnt = 1;
            x += 1;
            while (ls(nums, x)) {
                cnt++;
                x += 1;
            }
            res = max(cnt, res);
        }

        return res;
    }
    */

    /* // Better Approach
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        int res = 0, cnt = 0, x = 0;
        unordered_map<int, int> umap;

        for (int i = 0; i < n; i++) {
            umap[nums[i]]++;
        }

        for (int i = 0; i < n; i++) {
            x = nums[i];
            cnt = 1;
            x += 1;
            while (umap[x] > 0) {
                cnt++;
                x += 1;
            }
            res = max(cnt, res);
        }


        return res;
    }*/

    // Optimal Approach
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums) {
            set.insert(num);
        }
        int longestConsecutiveSequence = 0;
        for (int num : nums) {
            if (set.find(num - 1) == set.end()) {
                int currentNumber = num;
                int currentConsecutiveSequence = 1;
                while (set.find(currentNumber + 1) != set.end()) {
                    currentNumber++;
                    currentConsecutiveSequence++;
                }
                longestConsecutiveSequence =
                    max(longestConsecutiveSequence, currentConsecutiveSequence);
            }
        }
        return longestConsecutiveSequence;
    }
};