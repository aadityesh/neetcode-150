class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int res = 1;
        int n = nums.size();
        vector<int> ans(n, 0);
        ans[0] = 1;
        // prefix
        for(int i = 1; i < n; i++) {
            res *= nums[i-1];
            ans[i] = res;
        }
        // suffix
        res = 1;
        for(int i = n-2; i>=0; i--) {
            res *= nums[i+1];
            ans[i] = ans[i] * res;
        }

        return ans;
    }
};