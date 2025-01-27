class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int res = 0, cnt = 0;

        for (int& i : nums) {
            if (i == 1) {
                cnt++;
                res = max(res, cnt);
            } else {
                cnt = 0;
            }
        }

        return res;
    }
};