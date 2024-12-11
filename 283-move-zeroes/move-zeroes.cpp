class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int n = nums.size();
        int current = 0; // index to fill from the start

        /*for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[current++] = nums[i];
            }
        }

        while (current < n) {
            nums[current++] = 0;
        }*/

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[current], nums[i]);
                current
                ++;
            }
        }
    }
}

;