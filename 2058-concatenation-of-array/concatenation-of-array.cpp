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
        for (int i = 0; i < n; i++)
            nums.push_back(nums[i]);
        
        return nums;
    }
};