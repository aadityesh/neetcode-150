class Solution {
public:
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