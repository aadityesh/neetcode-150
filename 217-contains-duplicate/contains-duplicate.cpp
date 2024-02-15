class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        
        // Brute - two nested loops
        // Better - HashMap

        // Best 
        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i - 1] == nums[i])
                return true;
        }

        return false;

    }
};