class Solution {
    vector<vector<int>> res;
    int target;

public:
    void dfs(int ind, int sum, vector<int> temp, vector<int>& input) {

        if (sum == target) {
            res.push_back(temp);
            return;
        }

        if (ind >= input.size() || sum > target) {
            return;
        }

        sum += input[ind];
        temp.push_back(input[ind]);
        dfs(ind + 1, sum, temp, input);

        sum -= input[ind];
        temp.pop_back();

        // skipping the duplicate elements at the same level.
        while ((ind + 1) < input.size() && input[ind] == input[ind + 1])
            ind++;

        dfs(ind + 1, sum, temp, input);
    }

    vector<vector<int>> combinationSum2(vector<int>& input, int _target) {
        this->target = _target;
        sort(input.begin(), input.end());
        dfs(0, 0, {}, input);
        return res;
    }
};