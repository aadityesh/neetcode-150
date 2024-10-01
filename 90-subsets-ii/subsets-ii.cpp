class Solution {
public:
    void generate(set<vector<int>>& st, vector<int>& nums, vector<int> temp,
                  int i) {

        if (i == nums.size()) {
            sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }

        temp.push_back(nums[i]);
        generate(st, nums, temp, i + 1);
        temp.pop_back();
        generate(st, nums, temp, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        int n = nums.size();

        set<vector<int>> st;
        vector<vector<int>> res;
        vector<int> temp;

        generate(st, nums, temp, 0);
        for (auto i : st)
            res.push_back(i);

        return res;
    }
};