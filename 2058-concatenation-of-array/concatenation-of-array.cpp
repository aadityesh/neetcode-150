class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(2 * n, 0);

        // Brute
        /* for (int i = 0; i < n; i++) {
             res[i] = nums[i];
             res[n + i] = nums[i];
         }
         return res;
         */
        // Optimal
        for (int i = 0; i < n; i++)
            nums.push_back(nums[i]);
        
        return nums;
    }
};