class Solution {
public:
    void combinations(vector<vector<int>>& res, vector<int>& temp,
                      vector<int>& input, int target, int sum, int ind) {

        if (ind == input.size() || sum > target) {
            return;
        }

        if (sum == target) {
            res.push_back(temp);
            return;
        }

        sum += input[ind];
        temp.push_back(input[ind]);
        combinations(res, temp, input, target, sum, ind);

        sum -= input[ind];
        temp.pop_back();
        combinations(res, temp, input, target, sum, ind + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& input, int target) {
        int ind = 0;
        int sum = 0;
        vector<vector<int>> res;
        vector<int> temp;
        combinations(res, temp, input, target, sum, ind);
        return res;
    }
};