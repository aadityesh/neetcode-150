class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        int i = 0;
        int j = n - 1;

        // [ 2, 7, 11, 15 ],

        int sum = 0;

        while (i < j) {

            sum = nums[i] + nums[j];

            if (sum == target)
                return {i+1, j+1};

            if (sum > target)
                j--;
            else
                i++;
        }

        return {-1, -1};
    }
};