class Solution {
public:
    int longestSubarray(vector<int>& a) {

        int n = a.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {

            int cntZero = 0;
            int j = i;

            for (int j = i; j < n; j++) {

                if (a[j] == 0)
                    cntZero++;

                if (cntZero > 1) {
                    ans = max(ans, j - i - 1);
                    break;
                }
                if (cntZero <= 1) {
                    ans = max(ans, j - i);
                }
            }
        }

        return ans;
    }
};