class Solution {
public:
    void recursive(int idx, vector<int>& nums, vector<int>& temp,
                   vector<vector<int>>& res) {

        if (idx >= nums.size()) {
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        recursive(idx + 1, nums, temp, res);
        temp.pop_back();
        recursive(idx + 1, nums, temp, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        recursive(0, nums, temp, res);

        return res;
    }
};