class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();
        int missing = 0;
        int range = 0;

        for(int i = 0; i < n; i++) {
            range ^= i;
            missing ^= nums[i];
        }

        return (missing ^ range ^ n);
    }
};