class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int curr = INT_MIN;
        int size = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (curr != nums[i]) {
                curr = nums[i];
                nums[size++] = curr;
            }
        }
        return size;
    }
};