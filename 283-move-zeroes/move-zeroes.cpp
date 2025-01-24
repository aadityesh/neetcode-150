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

        /*
        - R is non-zero
            - make the swap move to the next
        - R is zero
            - L will stand on the first pos from left (start, index = 0) to replaced with
              a non-zero element

        // 1 2 3 1 2 0 8 7 9 0
        */

        int L = 0; // contains position to fill with non-zero element

        // This approach is about picking 
        // non-zero elems and placing them
        // from the start (left/index=0)
        for (int R = 0; R < n; R++) {
            if (nums[R] != 0) {
                swap(nums[L], nums[R]);
                L++;
            }
        }
    }
}

;