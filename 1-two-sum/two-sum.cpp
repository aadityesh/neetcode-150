class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Brute - Two nested loops

        // Optimal
        unordered_map<int, int> umap;
        int i, sum, diff;
        i = sum = diff = 0;

        while (i < nums.size()) {
            int diff = target - nums[i];
            if (umap.find(diff) != umap.end()) {
                int j = umap[diff];
                // cout << j << endl;
                if (i != j) {
                    return {i, j};
                }
            }
            umap[nums[i]] = i;
            i++;
        }

        return {};
    }
};