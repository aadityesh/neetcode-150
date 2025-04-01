class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        /*
        1 2 3
        1 2 3 1 2 3

        1. Create a temp arr
        2. Run a loop for 2n times over input array

        */

        int n = nums.size();
        vector<int> ans(2 * n);

        for (int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }

        return ans;
    }
};