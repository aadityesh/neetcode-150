class Solution {
public:
    void generate(vector<int> subset, vector<vector<int>>& res,
                  vector<int> input, int idx) {

        if (idx == input.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(input[idx]);
        generate(subset, res, input, idx + 1);
        subset.pop_back();
        while (idx + 1 < input.size() && input[idx] == input[idx + 1])
            idx++;
        generate(subset, res, input, idx + 1);

        // 3 1 _
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();

        // set<vector<int>> st;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> temp;

        generate(temp, res, nums, 0);
        // for (auto i : st)
        //     res.push_back(i);

        return res;
    }
};