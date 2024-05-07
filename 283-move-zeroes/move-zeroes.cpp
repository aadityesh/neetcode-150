class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;

        if (n == 1)
            return;

        for (int i = 0; i < n; i++) {

            if (nums[i] == 0) {
                j = i;
                while (j <= n - 2 && nums[j] == 0)
                    j++;
                // cout << i << " " << j << endl;

                swap(nums[i], nums[j]);
            }
        }
    }
};