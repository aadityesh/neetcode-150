class Solution {
    vector<vector<int>> res;
    int target;
    void dfs(int ind, int sum, vector<int> temp, vector<int>& input) {

        if (sum == target) {
            res.push_back(temp);
            return;
        }

        for (int j = ind; j < input.size(); j++) {

            if (sum + input[j] > target)
                return;

            sum += input[j];
            temp.push_back(input[j]);

            dfs(j, sum, temp, input);

            sum -= input[j];
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& input, int _target) {
        vector<int> temp;
        this->target = _target;
        sort(input.begin(), input.end());
        dfs(0, 0, temp, input); // ind, sum, temp, inp
        return res;
    }
};