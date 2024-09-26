class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& input, int start) {
        if (start == input.size()) {
            res.push_back(input);
        }
        for (int i = start; i < input.size(); i++) {
            swap(input[start], input[i]);
            dfs(input, start + 1);
            swap(input[start], input[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};