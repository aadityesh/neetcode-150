class Solution {
public:
    /* // Brute-force approach
    bool ls(vector<int>& nums, int key) {
        for (int i : nums) {
            if (i == key)
                return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        int res = 0, cnt = 0, x = 0;

        for (int i = 0; i < n; i++) {
            x = nums[i];
            cnt = 1;
            x += 1;
            while (ls(nums, x)) {
                cnt++;
                x += 1;
            }
            res = max(cnt, res);
        }

        return res;
    }
    */

    /* // Better Approach
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        int res = 0, cnt = 0, x = 0;
        unordered_map<int, int> umap;

        for (int i = 0; i < n; i++) {
            umap[nums[i]]++;
        }

        for (int i = 0; i < n; i++) {
            x = nums[i];
            cnt = 1;
            x += 1;
            while (umap[x] > 0) {
                cnt++;
                x += 1;
            }
            res = max(cnt, res);
        }


        return res;
    }*/

    // Optimal Approach
    int longestConsecutive(vector<int>& nums) {

        if (nums.size() == 0)
            return nums.size();

        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0, cnt = 1;

        for (const int& i : st) {
            if (st.find(i - 1) == st.end()) {
                int x = i;
                x += 1;
                while (st.find(x) != st.end()) {
                    cnt++;
                    x += 1;
                }
                res = max(res, cnt);
                cnt = 1;
            }
        }

        return res;
    }
};