class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // Brute - two nested loops
        /*int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j])
                    return true;
            }
        }
        return false;*/

        // Better - HashMap
        // unordered_map<int, int> umap;
        // for (auto i : nums) {
        //     umap[i]++;
        // }
        // for (auto i : umap) {
        //     if (i.second > 1)
        //         return false;
        // }
        // return true;

        // Best
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i])
                return true;
        }

        return false;
    }
};