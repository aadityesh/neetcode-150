class Solution {
public:
    int findMin(vector<int>& nums) {

        // brute - force 
        int n = nums.size();
        int mini = nums[0];
        for(int i = 1; i < n; i++) {
           mini = min(mini, nums[i]);
        }
        return mini;
        
    }
};