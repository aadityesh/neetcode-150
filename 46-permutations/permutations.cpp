
class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<bool>& hash, vector<int>& nums,
             vector<int>& temp) {

        if (temp.size() == nums.size()) {
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (hash[i] == false) {
                hash[i] = true;
                temp.push_back(nums[i]);
                dfs(res, hash, nums, temp);
                hash[i] = false;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> hash(n, false);

        dfs(res, hash, nums, temp);

        return res;
    }
    /*

        _ _ _
        3 2 1 = N!

                1 2 3
            1 2 3
        1 2 3


    */
};