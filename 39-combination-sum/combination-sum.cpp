class Solution {
public:
    void combinations(vector<vector<int>> &res, vector<int>& temp,
                      vector<int> &input, int target, int ind) {

        if (ind == input.size()) {
            if (target == 0)
                res.push_back(temp);
            return;
        }

        if (input[ind] <= target) {
            temp.push_back(input[ind]);
            combinations(res, temp, input, target - input[ind], ind);
            temp.pop_back();
        }
        combinations(res, temp, input, target, ind + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& input, int target) {
        int ind = 0;
        vector<vector<int>> res;
        vector<int> temp;
        combinations(res, temp, input, target, ind);
        return res;
    }
};