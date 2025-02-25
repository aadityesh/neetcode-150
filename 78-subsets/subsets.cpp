class Solution {
    vector<vector<int>> res;
public:
    void dfs(int ind, vector<int> &nums, vector<int> temp) {

        if(ind >= nums.size()) {
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[ind]);
        dfs(ind + 1, nums, temp);

        temp.pop_back();
        dfs(ind + 1, nums, temp);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        dfs(0, nums, temp);
        return res;
    }
};