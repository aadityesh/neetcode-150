class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int missing = 0;
        int present = 0;
        int n = nums.size();

        for (int i = 0; i <= n; i++) {
            missing ^= i;
            if (i < n)
                present ^= nums[i];
        }

        return present ^ missing;
    }
};