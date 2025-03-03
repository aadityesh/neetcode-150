class Solution {
    vector<vector<int>> res;
    int target;

public:
    void dfs(int ind, int sum, vector<int> temp, vector<int>& input) {

        if (sum == target) {
            res.push_back(temp);
            return;
        }

        for (int j = ind; j < input.size(); j++) {

            if (j > ind && input[j] == input[j - 1])
                continue;

            if (sum + input[j] > target) {
                break;
            }

            sum += input[j];
            temp.push_back(input[j]);

            dfs(j + 1, sum, temp, input);

            sum -= input[j];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& input, int _target) {
        this->target = _target;
        sort(input.begin(), input.end());
        dfs(0, 0, {}, input);
        return res;
    }
};