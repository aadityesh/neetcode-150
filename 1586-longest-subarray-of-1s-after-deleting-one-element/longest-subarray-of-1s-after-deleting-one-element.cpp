class Solution {
public:
    int longestSubarray(vector<int>& a) {

        int n = a.size();
        int ans = 0;

        // for (int i = 0; i < n; i++) {

        //     int cntZero = 0;

        //     for (int j = i; j < n; j++) {

        //         if (a[j] == 0)
        //             cntZero++;

        //         if (cntZero > 1) { // More than one Zero
        //             ans = max(ans, j - i - 1);
        //             break;
        //         }

        //         if (cntZero <= 1) { // No zero / One Zero
        //             ans = max(ans, j - i);
        //         }
        //     }
        // }

        int i = 0;
        int j = 0;
        int cntZero = 0;

        while (j < n) {

            if (a[j] == 0)
                cntZero++;

            while (cntZero > 1) {
                if (a[i] == 0)
                    cntZero--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans - 1;
    }
};