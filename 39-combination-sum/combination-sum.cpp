class Solution {
    vector<vector<int>> res;
    int target;
    void dfs(int ind, int sum, vector<int> temp, vector<int>& input) {

        if (ind >= input.size()) {
            if (sum == target)
                res.push_back(temp);
            return;
        }

        if (sum > target) {
            return;
        }

        temp.push_back(input[ind]);
        sum += input[ind];
        dfs(ind, sum, temp, input);

        temp.pop_back();
        sum -= input[ind];
        dfs(ind + 1, sum, temp, input);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& input, int _target) {
        vector<int> temp;
        this->target = _target;
        dfs(0, 0, temp, input); // ind, sum, temp, inp
        return res;
    }
};