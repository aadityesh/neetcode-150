class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();
        int L = 0;
        int R = 0;
        int res = 0;

        vector<int> prefix(n);
        vector<int> suffix(n);

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            prefix[i] = maxi;
            if (height[i] > maxi)
                maxi = height[i];
        }
        maxi = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = maxi;
            if (height[i] > maxi)
                maxi = height[i];
        }

        for(int i = 0; i < n; i++) {
            if(height[i] < prefix[i] && height[i] < suffix[i]) {
                res += (min(prefix[i], suffix[i]) - height[i]);
            }
        }

        return res;
    }
};